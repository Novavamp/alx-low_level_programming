#include "main.h"

/**
 * _puts - A function that prints a string wiht a new line
 * @str: the string
 * Return: The string
 */
void _puts(char *str)
{
	int a = 0;

	while (str[a] != '\0')
	{
		_puts(str[a]);
		a++;
	}
	return (str);
}

