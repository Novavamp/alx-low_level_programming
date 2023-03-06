#include "main.h"

/**
 * _memset - function fills the first n bytes of the memory area
 * @n: The bytes being filled
 * @s: The pointer to the memory area
 * @b: The constant char byte
 *
 * Return: The pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int index;
	unsigned char *memory = s, value = 'b';

	for (index = 0; index < n; index++)
		memory[index] = value;

	return (memory);
}
