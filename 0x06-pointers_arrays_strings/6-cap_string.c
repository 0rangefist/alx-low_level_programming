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
	while (*s_ptr != '\0')
	{
		if (s_ptr == s) /* if the current pointer is at the very start */
		{
			/*capitalize the very first char if it is lowercase alphabet*/
			if (*s_ptr >= 'a' && *s_ptr <= 'z')
			{
				/* subtract 32 from char value to make it uppercase */
				*s_ptr = *s_ptr - 32;
			}
		}
		else
		{
			/* track the previous char */
			s_previous_ptr = s_ptr - 1;

			/* if current char is lowercase alphabet & previous char is */
			/* .?!;({ ' ' \n or \t */
			if ((*s_ptr >= 'a' && *s_ptr <= 'z')
				&& (*s_previous_ptr == '.' || *s_previous_ptr == ','
					|| *s_previous_ptr == ';' || *s_previous_ptr == ':'
					|| *s_previous_ptr == '?' || *s_previous_ptr == '!'
					|| *s_previous_ptr == ' ' || *s_previous_ptr == '"'
					|| *s_previous_ptr == '(' || *s_previous_ptr == ')'
					|| *s_previous_ptr == '{' || *s_previous_ptr == '}'
					|| *s_previous_ptr == '\n' || *s_previous_ptr == '\t'))
			{
				*s_ptr = *s_ptr - 32; /* at start of a word so capitalize*/
			}
		}
		s_ptr++;
	}
	return (s);
}
