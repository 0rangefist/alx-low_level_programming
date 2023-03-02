#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 *
 * @s: pointer to a string
 *
 * Return: modified string
 */
char *cap_string(char *s)
{
	char *s_ptr;
	char *s_previous_ptr;

	s_ptr          = s;
	s_previous_ptr = s;

	/* traverse through each char of string */
	while (*s_ptr != '\0')
	{
		/* if the current pointer is at the very start */
		if (s_ptr == s)
		{
			/*capitalize the very first char if it is lowercase alphabet*/
			if (*s_ptr >= 'a' && *s_ptr <= 'z')
			{
				/* subtract 32 from char value to make it uppercase */
				*s_ptr = *s_ptr - 32;
			}
		}
		/* else if the current pointer isn't at the very start*/
		else
		{
			/* track the previous char */
			s_previous_ptr = s_ptr - 1;

			/* if current char is lowercase alphabet & previous char is */
			/* .?! ' ' \n or \t */
			if ((*s_ptr >= 'a' && *s_ptr <= 'z')
				&& (*s_previous_ptr == '.' || *s_previous_ptr == '?'
					|| *s_previous_ptr == '!' || *s_previous_ptr == ' '
					|| *s_previous_ptr == '\n' || *s_previous_ptr == '\t'))
			{
				/* then current char is the start of a word so capitalize*/
				*s_ptr = *s_ptr - 32;
			}
		}
		s_ptr++;
	}

	return (s);
}
