#include "main.h"

/**
 * print_alphabet - print lowercase alphabet
 *
 * Description: prints the alphabet in lower case then a new line
 *
 * Return: 0 on success, non-zero on error.
 */

void print_alphabet(void)
{
	int i;

	for (i = 'a'; i <= 'z'; i++)
	{
		_putchar(i);
	}

	_putchar('\n');
}
