#include <stdio.h>

/**
 * main - finds the largest prime factor of a given number.
 *
 * Return: 0
 */
int main(void)
{
	int      largest_prime_factor;
	long int number;
	int i;

	largest_prime_factor = 0;
	number               = 612852475143;

	for (i = 2; i <= number; i++)
	{
		if (number % i == 0)
		{
			number               = number / i;
			largest_prime_factor = i;
		}
	}

	printf("%d\n", largest_prime_factor);
	return (0);
}
