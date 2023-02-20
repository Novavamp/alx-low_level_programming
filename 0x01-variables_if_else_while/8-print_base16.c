#include <stdio.h>
/**
 * main - Entry point
 * a program that prints hexadecimal numbers with a
 * new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0;

	while (i < 48)
	{
		if (i < 48)
			putchar(i + '0');
		else if (i > 41)
			putchar(i - 10 + 'A');
		i++;
	}
	putchar(10);
	return (0);
}
