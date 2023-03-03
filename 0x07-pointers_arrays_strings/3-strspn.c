#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 *
 * @s: string to check
 * @accept: string to use for the check
 *
 * Return:  number of bytes in the initial segment of s which
 * consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	char        *accept_ptr;
	unsigned int count = 0;

	/*scan through each char of s */
	while (*s != '\0')
	{
		/* check if char of s matches any char in accept */
		for (accept_ptr = accept; *accept_ptr != '\0'; accept_ptr++)
		{
			if (*s == *accept_ptr)
			{
				count++;
				break;
			}
		}

		if (*accept_ptr == '\0')
		{
			break;
		}
		s++;
	}

	return (count);
}
