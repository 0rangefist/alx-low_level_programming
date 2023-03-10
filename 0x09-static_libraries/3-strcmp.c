#include "main.h"

/**
 * _strcmp - compares two strings
 *
 * @s1: first pointer to string
 * @s2: second pointer to string
 *
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	char *s1_ptr;
	char *s2_ptr;

	s1_ptr = s1;
	s2_ptr = s2;

	while (*s1_ptr != '\0' && *s2_ptr != '\0' && (*s1_ptr == *s2_ptr))
	{
		s1_ptr++;
		s2_ptr++;
	}

	return (*s1_ptr - *s2_ptr);
}
