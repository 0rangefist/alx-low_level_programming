#include "main.h"

/**
 * rot13 - encodes a string using rot13
 *
 * @s: pointer to a string
 *
 * Return: modified string
 */
char *rot13(char *s)
{
	char *s_ptr;
	char *chars_ptr;
	char *cipher_ptr;

	char chars[]  = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	char cipher[] = "nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmM";

	s_ptr = s;
	while (*s_ptr != '\0')
	{
		chars_ptr  = chars;
		cipher_ptr = cipher;
		while (*chars_ptr != '\0' && *s_ptr != *chars_ptr)
		{
			chars_ptr++;
			cipher_ptr++;
		}

		if (*s_ptr == *chars_ptr)
		{
			*s_ptr = *cipher_ptr;
		}

		s_ptr++;
	}
	return (s);
}
