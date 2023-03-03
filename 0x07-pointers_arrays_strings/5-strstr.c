#include "main.h"

/**
 * _strstr - finds the first occurrence of the
 * substring needle in the string haystack
 *
 * @haystack: string to check
 * @needle: string to use for the check
 *
 * Return: pointer  to the beginning of the located
 * substring, or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *haystack_cpy;
	char *needle_cpy;

	/*scan through haystack */
	while (*haystack != '\0')
	{
		/* look for the 1st char of needle within haystack */
		if (*needle == *haystack)
		{
			/* start comparing needle with haystack*/
			haystack_cpy = haystack;
			needle_cpy   = needle;
			while (*needle_cpy != '\0')
			{
				if (*haystack_cpy != *needle_cpy)
				{
					break;
				}
				/* move to next char in needle and haystack_cpy */
				needle_cpy++;
				haystack_cpy++;
			}
			/* if needle is fully matched */
			if (*needle_cpy == '\0')
			{
				/* return the haystack pointer where the match happened */
				return (haystack);
			}
		}
		haystack++;
	}
	/* substring not found so return NULL */
	return (0);
}
