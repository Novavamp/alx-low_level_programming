#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

#define ERROR_CODE (98)

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
	printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x
			%02x %02x %02x %02x %02x %02x %02x\n",
		magic[0], magic[1], magic[2], magic[3],
		magic[4], magic[5], magic[6], magic[7],
		magic[8], magic[9], magic[10], magic[11],
		magic[12], magic[13], magic[14], magic[15]);

	printf("  Class:                             ");
	switch (elf_header->e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_header->e_ident[EI_CLASS]);
		break;
	}

	printf("  Data:                              ");
	switch (elf_header->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_header->e_ident[EI_DATA]);
		break;
	}

	printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (elf_header->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_header->e_ident[EI_OSABI]);
		break;
	}

	printf("  ABI Version:			%d\n", elf_header->e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (elf_header->e_type)
	{
	case ET_NONE:
		printf("NONE (Unknown type)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_header->e_type);
		break;
	}

	printf("  Entry point address:			0x%lx\n", elf_header->e_entry);
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
	return (0);
}
