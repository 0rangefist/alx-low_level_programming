#include "main.h"

/**
 * is_prime_number - check if a number is prime
 *
 * @n: number to check
 *
 * Return: 1 if n is prime otherwise return 0;
 */
int is_prime_number(int n)
{
	if (n == 2)
	{
		return (1);
	}
	if (n < 2)
	{
		return (0);
	}
	if (n % 2 == 0)
	{
		return (0);
	}

	return (is_prime_recursive_helper(n, 3));
}

/**
 * is_prime_recursive_helper - recursively checks if a number is prime
 *
 * @n: number to check for primality
 * @div: divisor to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_recursive_helper(int n, int div)
{
	if (div >= n)
	{
		return (1);
	}
	if (n % div == 0)
	{
		return (0);
	}
	return (is_prime_recursive_helper(n, div + 2));
}
