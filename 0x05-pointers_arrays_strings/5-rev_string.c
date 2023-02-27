#include "main.h"

/**
 * rev_string - A function that reverses a string
 * @s: the string being reversed
 * Return: the string
 */
void rev_string(char *s)
{
	int a = 0; b;

	while (s[b++])
		b++;

	for (b = a - 1; b >= 0; b--)
	{
		_putchar(s[b]);
	}
}
