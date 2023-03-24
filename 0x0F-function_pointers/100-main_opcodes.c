#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments passed to the program
 *
 * Return: 0 if the program completes successfully, 1 if there is an error
 */
int main(int argc, char **argv)
{
    int i, num_bytes;
    unsigned char *opcodes;

    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }

    num_bytes = atoi(argv[1]);

    if (num_bytes < 0)
    {
        printf("Error\n");
        return 2;
    }

    opcodes = (unsigned char *)main;

    for (i = 0; i < num_bytes; i++)
    {
        printf("%02x", *(opcodes + i));
    }

    printf("\n");

    return 0;
}
