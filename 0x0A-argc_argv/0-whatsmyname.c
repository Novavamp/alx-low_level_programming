#include "main.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	char *name = __FILE__;
	int i = 0;

	while (name[i])
	{
		_putchar(name[i]);
		i++;
	}
	_putchar('\n');

	return (0);
}
