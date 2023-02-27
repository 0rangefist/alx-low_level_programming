#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to a string
 *
 * Return: nothing
 */

void rev_string(char *s)
{
	int  length;
	int  i;
	char tmp;

	i      = 0;
	length = 0;

	/* Find the length of the string */
	while (s[i++])
	{
		length++;
	}

	/* reverse the string*/
	for (i = 0; i < length / 2; i++)
	{
		tmp               = s[i];
		s[i]              = s[length - i - 1];
		s[length - i - 1] = tmp;
	}
}
