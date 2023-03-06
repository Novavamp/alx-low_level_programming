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
	unsigned int i;
	char fill = b;

	while (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			s[i] = bytes;
		}
		n--;
	}
	return (s);
}