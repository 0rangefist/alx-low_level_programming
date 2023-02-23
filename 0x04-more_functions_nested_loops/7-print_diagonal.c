#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal.
 *
 * @n: the number of characters of the line
 *
 * Return: void
 */

void print_diagonal(int n)
{
	while (n > 0)
	{
		_putchar('\\');
		n--;
	}

	_putchar('\n');
}
