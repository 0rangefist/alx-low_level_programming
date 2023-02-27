#include "main.h"
#include <stdio.h>

/**
 * print_rev - prints a string in reverse, followed by a new line
 *
 * @str: pointer to a string
 *
 * Return: nothing
 */

void print_rev(char *str)
{
	int length;
	int i;
	int j;

	j = 0;

	length = 0;

	/* Find the length of the string */
	while (str[j++])
	{
		length++;
	}

	/* Print the chars of string in reverse*/
	for (i = length - 1; i >= 0; i--)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
