#include "main.h"

/**
 * puts2 -  prints every other character of a string,
 * starting with the first character, followed by a new line.
 *
 * @str: pointer to a string
 *
 * Return: nothing
 */

void puts2(char *str)
{
	int length;
	int i;

	i      = 0;
	length = 0;

	/* Find the length of the string */
	while (str[i++])
	{
		length++;
	}

	/* print every other character*/
	for (i = 0; i <= length; i += 2)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
