#include "main.h"

/**
 * _memset - fills memory with a constant byte
 *
 * @s: pointer to a string
 * @b: constant byte used for filling memory
 * @n: number of bytes of memory to fill
 *
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int   i;
	char *s_ptr;

	s_ptr = s;
	for (i = 0; i < n; i++, s_ptr++)
	{
		*s_ptr = b;
	}

	return (s);
}
