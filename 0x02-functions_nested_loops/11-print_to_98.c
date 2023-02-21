#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - prints natural numbers from input
 *               up until the number 98
 * @n: input integer
 * Return: void
 */

void print_to_98(int n)
{
	while (n < 98)
	{
		printf("%i, ", n);
		n++;
	}
	while (n > 98)
	{
		printf("%i, ", n);
		n--;
	}
	if (n == 98)
	{
		printf("%i", n);
	}

	printf("\n");
}
