#include "main.h"

/**
 * print_number -  prints an integer usin _putchar
 *
 * @n: number to print
 *
 * Return: void
 */
void print_number(int n)
{
	char sign;
	int  num_of_digits;
	int  n_copy;
	int  i;
	int  j;
	char digit;
	int  divisor;

	n_copy        = n;
	num_of_digits = 0;
	/* get the num of digits of integer */
	while (n_copy != 0)
	{
		num_of_digits++;
		n_copy /= 10;
	}
	if (n == 0)
	{
		_putchar('0');
		return;
	}
	if (n < 0)
	{
		n    = -n;
		sign = '-';
		_putchar(sign);
	}

	/* Iterate from the highest digit to the lowest digit*/
	for (i = num_of_digits; i > 0; i--)
	{
		divisor = 1;
		for (j = 0; j < i - 1; j++)
		{
			divisor = divisor * 10;
		}
		digit = (n / divisor) % 10;
		_putchar(digit + '0');
	}
}
