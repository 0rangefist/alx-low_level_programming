#include "main.h"

/**
 * _strcpy -  copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 *
 * @dest: destination pointer to a string
 * @src: source pointer to a string
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int length;
	int i;

	i      = 0;
	length = 0;

	/* Find the length of the src string */
	while (src[i++])
	{
		length++;
	}

	/* copy elements from src to dest */
	for (i = 0; i <= length; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
