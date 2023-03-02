#include "main.h"

/**
 * leet - encodes a string into 1337
 *
 * @s: pointer to a string
 *
 * Return: modified string
 */
char *leet(char *s)
{
	char *s_ptr;
	char *chars_ptr;
	char *nums_ptr;

	char chars[] = "aAeEoOtTlL";
	char nums[]  = "4433007711";

	s_ptr = s;
	while (*s_ptr != '\0')
	{
		chars_ptr = chars;
		nums_ptr  = nums;
		while (*chars_ptr != '\0' && *s_ptr != *chars_ptr)
		{
			chars_ptr++;
			nums_ptr++;
		}

		if (*s_ptr == *chars_ptr)
		{
			*s_ptr = *nums_ptr;
		}

		s_ptr++;
	}
	return (s);
}
