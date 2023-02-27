#include "main.h"

/**
 * _puts - A function that prints a string wiht a new line
 * @str: the string
 * Return: The strinig
 */
void _puts(char *str)
{
	int a = 0;

	while (str[a] != '\0')
	{
		_putchar(str[a]);
		a++;
	}
	_putchar('\n');
}

