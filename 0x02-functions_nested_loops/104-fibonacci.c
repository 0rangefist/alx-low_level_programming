#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers.
 *
 * Return: 0
 */
int main(void)
{
	int           i;
	unsigned long fib1 = 1;
	unsigned long fib2 = 2;
	unsigned long next_fib;

	printf("%lu, %lu", fib1, fib2);

	for (i = 3; i <= 98; i++)
	{
		next_fib = fib1 + fib2;
		printf(", %lu", next_fib);
		fib1 = fib2;
		fib2 = next_fib;
	}

	printf("\n");
	return (0);
}

