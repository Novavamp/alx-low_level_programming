#include "main.h"

/**
 * print_square - A function that prints a square
 * @size: The size of the square
 * @#: Character to print the aquare
 *
 * Return: Always 0.
 */
void print_square(int size)
{
	int ht, wid;

	if (size > 0)
	{
		for (ht = 0; ht < size; ht++)
		{
			for (wid = 0; wid < size; wid++)
				_putchar('#');

			if (ht == size - 1)
				continue;
			_putchar('\n');
		}
	}

	_putchar('\n');
}
