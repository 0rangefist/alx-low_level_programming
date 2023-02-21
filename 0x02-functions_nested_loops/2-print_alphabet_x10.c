#include "main.h"

/**
 * print_alphabet_x10 - print lowercase alphabet x10
 *
 * Description:  prints 10 times the alphabet, in lowercase,
 * followed by a new line
 *
 * Return: 0 on success, non-zero on error.
 */

void print_alphabet_x10(void)
{
	int j;
	int i;

	for (j = 0; j < 10; j++)
	{
		for (i = 'a'; i <= 'z'; i++)
		{
			_putchar(i);
		}

		_putchar('\n');
	}
}
