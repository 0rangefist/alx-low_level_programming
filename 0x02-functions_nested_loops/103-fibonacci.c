#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers.
 *
 * Return: 0
 */
int main(void)
{
	unsigned long fib1 = 1;
	unsigned long fib2 = 2;
	unsigned long next_fib;
	int           sum = 2;

	while (fib2 < 4000000)
	{
		next_fib = fib1 + fib2;
		fib1     = fib2;
		fib2     = next_fib;

		if (fib2 % 2 == 0)
		{
			sum = sum + fib2;
		}
	}

	printf("%i\n", sum);
	return (0);
}

