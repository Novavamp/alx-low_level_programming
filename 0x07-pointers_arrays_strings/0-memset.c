#include "main.h"
#include <string.h>

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
	unsigned int num;
	unsigned char *memory = s, value = b;

	for (num = 0; num < n; num++)
		memory[num] = value;

	return (memory);
}
