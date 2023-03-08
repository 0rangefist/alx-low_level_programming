#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 *
 * @s: pointer to a string
 *
 * Return: length of the string as an int
 */
int _strlen_recursion(char *s)
{
	if (*s != '\0')
	{ /* make call to next ptr if curr val isnt null byte */
		return (_strlen_recursion(s + 1) + 1);
	}
	else
	{
		return (0);
	}
}
