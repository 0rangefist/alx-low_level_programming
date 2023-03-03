#include "main.h"

/**
 * _strchr -  locates a character in a string
 *
 * @s: string to search
 * @c: char to look for in string
 *
 * Return: pointer to first location of c else NULL
 */
char *_strchr(char *s, char c)
{
	char *s_ptr = s;

	while (*s_ptr != '\0')
	{
		if (*s_ptr == c)
		{
			return (s_ptr);
		}
		s_ptr++;
	}
	return (0); /* return NULL */
}
