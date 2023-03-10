#include "main.h"

/**
 * _strpbrk - locates the first occurrence in the string s
 * of any of the bytes in the string accept
 *
 * @s: string to check
 * @accept: string to use for the check
 *
 * Return: pointer of first location in s where a byte
 * in accept makes a match
 */
char *_strpbrk(char *s, char *accept)
{
	char *accept_ptr;

	/*scan through each char of s */
	while (*s != '\0')
	{
		/* check if char of s matches any char in accept */
		for (accept_ptr = accept; *accept_ptr != '\0'; accept_ptr++)
		{
			if (*s == *accept_ptr)
			{
				return (s);
			}
		}
		s++;
	}
	return (0); /* return NULL */
}
