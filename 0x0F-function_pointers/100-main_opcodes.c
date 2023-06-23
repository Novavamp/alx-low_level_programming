#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - function that prints opcodes of its own main function
 * @number_bytes: number of bytes to print
 */
void print_opcodes(int number_bytes);

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument value
 * Return: always 0
 */
int main(int argc, char **argv)
{
	int number_bytes;

	if (argc != 2)
	{
		printf("Error\n");
		return 1;
	}

	number_bytes = atoi(argv[1]);

	if (number_bytes < 0)
	{
		printf("Error\n");
		return 2;
	}

	print_opcodes(number_bytes);

	return 0;
}

void print_opcodes(int number_bytes)
{
	unsigned char *main_ptr = (unsigned char *)main;
	int i;

	for (i = 0; i < number_bytes; i++)
	{
		printf("%02x ", main_ptr[i]);
	}

	printf("\n");
}
