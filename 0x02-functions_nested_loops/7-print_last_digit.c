#include "main.h"

/**
 * print_last_digit - prints last digit of a num
 * @n: character to check
 *  Return: int
 */

int print_last_digit(int n)
{
	int  last_digit;
	last_digit = n % 10;

	if (n < 0)
	{
		last_digit = -last_digit;
	}
	_putchar('0' + last_digit);
	return (last_digit);
}
