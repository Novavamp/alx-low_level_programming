#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

#define ERROR_CODE 98

/**
 * error_exit - Print error message and exit with error code 98
 * @msg: The error message to display
 */
void error_exit(const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(ERROR_CODE);
}

/**
 * print_elf_header - Display the information in the ELF header
 * @elf_header: Pointer to the ELF header structure
 */
void print_elf_header(Elf64_Ehdr *elf_header)
{
	const unsigned char *magic = elf_header->e_ident;
	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
		magic[0], magic[1], magic[2], magic[3],
		magic[4], magic[5], magic[6], magic[7],
		magic[8], magic[9], magic[10], magic[11],
		magic[12], magic[13], magic[14], magic[15]);

	print_string_value("Class", elf_header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	print_string_value("Data", elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian"
										: "2's complement, big endian");
	printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);
	switch (elf_header->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:   print_string_value("OS/ABI", "UNIX - System V"); break;
	case ELFOSABI_HPUX:   print_string_value("OS/ABI", "UNIX - HP-UX"); break;
	case ELFOSABI_NETBSD: print_string_value("OS/ABI", "UNIX - NetBSD"); break;
	case ELFOSABI_LINUX:  print_string_value("OS/ABI", "UNIX - Linux"); break;
	case ELFOSABI_SOLARIS:print_string_value("OS/ABI", "UNIX - Solaris"); break;
	default:              printf("  OS/ABI:                            <unknown: %x>\n", elf_header->e_ident[EI_OSABI]);
	}
	printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
	switch (elf_header->e_type)
	{
	case ET_NONE: print_string_value("Type", "NONE (Unknown type)"); break;
	case ET_REL:  print_string_value("Type", "REL (Relocatable file)"); break;
	case ET_EXEC: print_string_value("Type", "EXEC (Executable file)"); break;
	case ET_DYN:  print_string_value("Type", "DYN (Shared object file)"); break;
	case ET_CORE: print_string_value("Type", "CORE (Core file)"); break;
	default:      printf("  Type:                              <unknown: %x>\n", elf_header->e_type);
	}

	printf("  Entry point address:               0x%lx\n", elf_header->e_entry);
}

/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr elf_header;

	if (argc != 2)
		error_exit("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Cannot open file");

	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		error_exit("Error: Cannot read ELF header");

	/* Check if the file is an ELF file */
	if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
		error_exit("Error: Not an ELF file");

	/* Display the ELF header information */
	print_elf_header(&elf_header);

	close(fd);
	return 0;
}
