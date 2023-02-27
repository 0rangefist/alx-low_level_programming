#include "main.h"

/**
 * _puts - prints a string, followed by a new line
 *
 * @str: pointer to a string
 *
 * Return: nothing
 */

void _puts(char *str)
{
	int length;
	int i;

	length = 0;
	/* Find the length of the string */
	while (*s++)
	{
		length++;
	}

	/* Print the chars of string in reverse*/
	for (i = length - 1; length >= 0; i--)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
