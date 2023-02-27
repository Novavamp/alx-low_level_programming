#include "main.h"

/**
 * print_rev - func that prints a string in rev and new line
 * @s: the string
 * Return: The string
 */
void print_rev(char *s)
{
	int i, x;

	x = 0;

	while (s[x] != '\0')
		x++;

	for (i = x - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
