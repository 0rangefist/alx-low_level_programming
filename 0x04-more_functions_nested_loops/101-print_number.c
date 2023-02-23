#include "main.h"

/**
 * print_number - Prints an integer.
 * @num: The integer to be printed.
 */

void print_number(int num)
{
	int divisor;
	int remainder;

	divisor = 1;
	remainder = 0;

	/* Check if the number is negative */
	if (num < 0)
	{
		_putchar('-');
		num = num * -1;
	}

	/* Find the divisor needed to print the digits of the number */
	while (num / divisor > 9)
	{
		divisor = divisor * 10;
	}

	/* Print each digit of the number starting from the leftmost */
	while (divisor != 0)
	{
		remainder = (num / divisor) % 10;
		_putchar(remainder + '0');
		divisor = divisor / 10;
	}
}
