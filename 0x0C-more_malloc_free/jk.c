#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int _isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

/**
 * _strlen - calculates the length of a string
 * @s: the string to calculate the length of
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
    int len = 0;

    while (*s++)
        len++;

    return (len);
}

/**
 * print_error - prints an error message and exits with status 98
 */
void print_error(void)
{
    int i;
    char *error = "Error\n";

    for (i = 0; error[i]; i++)
        _putchar(error[i]);

    exit(98);
}

/**
 * multiply - multiplies two numbers
 * @num1: the first number
 * @num2: the second number
 */
void multiply(char *num1, char *num2)
{
    int len1 = 0, len2 = 0, i, j, carry, product, sum;
    int *result;

    len1 = _strlen(num1);
    len2 = _strlen(num2);

    result = calloc(len1 + len2, sizeof(int));
    if (result == NULL)
        print_error();

    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            product = (num1[i] - '0') * (num2[j] - '0');
            sum = result[i + j + 1] + product + carry;
            carry = sum / 10;
            result[i + j + 1] = sum % 10;
        }
        result[i + j + 1] += carry;
    }

    for (i = 0; result[i] == 0 && i < len1 + len2 - 1; i++)
        ;

    for (; i < len1 + len2; i++)
        _putchar(result[i] + '0');

    _putchar('\n');

    free(result);
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: the arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
    int i;

    if (argc != 3)
        print_error();

    for (i = 0; argv[1][i]; i++)
        if (!_isdigit(argv[1][i]))
            print_error();

    for (i = 0; argv[2][i]; i++)
        if (!_isdigit(argv[2][i]))
            print_error();

    multiply(argv[1], argv[2]);

    return (0);
}

