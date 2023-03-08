#include "main.h"

int is_palindrome_helper(char *s, char *end);
int _strlen(char *s);

/**
 * is_palindrome - check if a string is a palindrome
 *
 * @s: string to check
 *
 * Return: 1 if palindrome otherwise return 0
 */
int is_palindrome(char *s)
{
	if (*s == '\0')
	{
		return (1);
	}
	else
	{
		return (is_palindrome_helper(s, s + _strlen(s) - 1));
	}
}

/**
 * is_palindrome_helper - helper fxn to check for palindrome
 *
 * @s: string to check
 * @end: pointer to the end of string
 *
 * Return: 1 if palindrome otherwise return 0;
 */
int is_palindrome_helper(char *s, char *end)
{
	if (s >= end)
	{
		return (1);
	}
	else if (*s != *end)
	{
		return (0);
	}
	else
	{
		return (is_palindrome_helper(s + 1, end - 1));
	}
}

/**
 * _strlen - returns the length of a string
 *
 * @s: pointer to a string
 *
 * Return: length of the string as an int
 */
int _strlen(char *s)
{
	if (*s != '\0')
	{ /* make call to next ptr if curr val isnt null byte */
		return (_strlen(s + 1) + 1);
	}
	else
	{
		return (0);
	}
}
