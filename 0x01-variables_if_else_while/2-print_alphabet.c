#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char i = 'a';

	while (i < 'z')
	{
		putchar(i);
		i++;
	}
	putchar('z');
	return (0);
}
