#include "main.h"

/**
 * _puts - A function that prints a string wiht a new line
 * @str: the string
 * Return: 0.
 */
void _puts(char *str)
{
	int a = 0;

	while (str[a] != '\0')
	{
		_puts(str[a]);
		a++;
	}
	_puts('\n');
}

