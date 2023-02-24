#include "main.h"

/**
 * print_numbers - A function that prints numbers followed by a new line.
 *
 * Return - Always 0.
 */
void print_numbers(void)
{
	int i;

	for (i = 0; i <= 9; i++)
		_putchar((i % 10) + '0');

	_putchar('\n');
}
