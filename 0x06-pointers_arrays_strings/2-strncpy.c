#include "main.h"

/**
 * _strncpy - copies a string
 *
 * @dest: pointer to destination string
 * @src: pointer to source string
 * @n: num of chars of src to use
 *
 * Return: pointer to resulting destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *dest_ptr;
	char *src_ptr;

	dest_ptr = dest;

	/* Iterate through src_ptr n times, copying each value over to *dest_ptr*/
	for (src_ptr = src; n > 0 && *src_ptr != '\0'; src_ptr++, dest_ptr++, n--)
	{
		*dest_ptr = *src_ptr;
	}

	/* if n is greater than 0, continue counting down till 0,  */
	/* filling the remaining n chars of dest with \0 */
	for(; n > 0; dest_ptr++, n--)
	{
		*dest_ptr = '\0';
	}

	return (dest);
}
