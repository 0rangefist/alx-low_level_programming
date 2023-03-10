#include "main.h"

/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 *
 * @dest: destination pointer
 * @src: source pointer
 * @n: number of bytes of memory to copy
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char        *src_ptr  = src;
	char        *dest_ptr = dest;
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest_ptr + i) = *(src_ptr + i);
	}

	return (dest);
}
