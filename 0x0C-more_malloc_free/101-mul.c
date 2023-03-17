#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _isdigit - checks if a character is a digit
 *
 * @c: character to be checked
 *
 * Return: 1 if @c is a digit, 0 otherwise
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * mul - multiplies two numbers
 *
 * @num1: first number to be multiplied
 * @num2: second number to be multiplied
 *
 * Return: product of @num1 and @num2
 */

int mul(int num1, int num2)
{
	return (num1 * num2);
}

/**
 * main - multiplies two numbers
 *
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 if successful, 1 otherwise
 */

int main(int argc, char *argv[])
{
	int num1, num2;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	if (!_isdigit(*argv[1]) || !_isdigit(*argv[2]))
	{
		printf("Error\n");
		return (1);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	printf("%d\n", mul(num1, num2));

	return (0);
}

