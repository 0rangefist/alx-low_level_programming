#include "main.h"

/**
 * _strcat -  concatenates two strings
 *
 * @dest: pointer to destination string
 * @src: pointer to source string
 *
 * Return: pointer to resulting destination string
 */
char *_strcat(char *dest, char *src)
{
	char *dest_ptr;
	char *src_ptr;

	dest_ptr = dest;
	src_ptr  = src;

	/* Move the pointer up to the point where the null terminator is*/
	while (*dest_ptr != '\0')
	{
		dest_ptr++;
	}

	/* Iterate through src_ptr, copying each value over to *dest_ptr, */
	/* which now has it's starting point where it's null terminator is */
	while (*src_ptr != '\0')
	{
		*dest_ptr = *src_ptr;
		dest_ptr++;
		src_ptr++;
	}

	/* We add a null terminator at the end of dest using dest_ptr */
	*dest_ptr = '\0';

	return (dest);
}
