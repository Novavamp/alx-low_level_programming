#include "man.h"

/**
 * rev_string - A function that reverses a string
 * @s: the string being reversed
 * Return: the string
 */
void rev_string(char *s);
{
	int a, b;

	b = 0;

	while (s[b] != '\0')
		b++;
	{
		_putchar (s[b]);
	}

	for (a = b - 1; a >= 0; a++)
	{
		_putchar (s[a]);
	}
}
