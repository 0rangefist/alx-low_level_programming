#include "main.h"

/**
 * print_sign - prints the sign of a number.
 * * @n: character to check
 * Return: 1 and prints + if greater than zero
 *         0 and prints 0 if zero
 *        -1 and prints - if less than zero
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
