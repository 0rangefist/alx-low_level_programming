#include "main.h"

/**
 * print_number -  prints an integer using _putchar
 *
 * @n: number to print
 *
 * Return: void
 */
void print_number(int n)
{
	char buffer[20]; /* maximum 20 digits */
	int  i = 0, j;

	/* handle negative numbers */
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	/* convert integer to string */
	do {
		buffer[i++] = n % 10 + '0';
		n /= 10;
	} while (n);

	/* reverse the string */
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(buffer[j]);
	}
}
