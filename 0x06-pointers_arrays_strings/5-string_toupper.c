#include "main.h"

/**
 * string_toupper - changes all lowercase letters of a string to uppercase
 *
 * @s: pointer to sting
 *
 * Return: void
 */
char *string_toupper(char *s)
{
	char *s_ptr;

	s_ptr = s;

	while (*s_ptr != '\0')
	{
		if (*s_ptr >= 'a' && *s_ptr <= 'z')
		{
			/* subtract 32 from char value to make it uppercase */
			*s_ptr = *s_ptr - 32;
		}
		s_ptr++;
	}

	return (s);
}
