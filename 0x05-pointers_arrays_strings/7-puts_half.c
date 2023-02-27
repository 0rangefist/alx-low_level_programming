#include "main.h"

/**
 * puts_half -   prints half of a string, followed by a new line
 *
 * @str: pointer to a string
 *
 * Return: nothing
 */

void puts_half(char *str)
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

	/* check if number of chars (length) is even or odd*/
	if (length % 2 == 0)
	{
		/* print the second half of the string */
		for (i = length / 2; i < length; i++)
		{
			_putchar(str[i]);
		}
	}
	else
	{
		/* print last n chars of string where */
		/* n = (length_of_the_string - 1) / 2 */

		for (i = (((length - 1) / 2) + 1); i < length; i++)
		{
			_putchar(str[i]);
		}
	}

	_putchar('\n');
}
