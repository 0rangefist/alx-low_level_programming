#include "main.h"

/**
 * _strncat -  concatenates two strings
 *
 * @dest: pointer to destination string
 * @src: pointer to source string
 * @n: num of chars of src to use
 *
 * Return: pointer to resulting destination string
 */
char *_strncat(char *dest, char *src, int n)
{
	char *dest_ptr;
	char *src_ptr;
	int   count;

	dest_ptr = dest;
	src_ptr  = src;
	count    = 0;

	/* Move the pointer up to the point where the null terminator is*/
	while (*dest_ptr != '\0')
	{
		dest_ptr++;
	}

	/* increment through the pointer & count how many chars are in src*/
	while (*src_ptr != '\0')
	{
		count++;
		src_ptr++;
	}

	/* check if num of chars in src(count) is less than n */
	if (count < n)
	{
		/* use count if it's less than n */
		n = count;
	}
	/* else use n */

	/* Iterate through src_ptr n times, copying each value over to *dest_ptr*/
	for (src_ptr = src; n > 0; src_ptr++, dest_ptr++, n--)
	{
		*dest_ptr = *src_ptr;
	}

	/* We add a null terminator at the end of dest using dest_ptr */
	*dest_ptr = '\0';

	return (dest);
}
