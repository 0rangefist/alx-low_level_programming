#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 *
 * @n: number whose square root is to be found
 *
 * Return: integer square root of n
 */
int _sqrt_recursion(int n)
{
	if (n == 0 || n == 1)
	{
		return (n);
	}
	else if (n < 0)
	{
		return (-1);
	}

	return (_sqrt_recursive_helper(n, 0, n));
}

/**
 * _sqrt_recursive_helper - recursive helper function to find the
 * square root of a number
 *
 * @n: number whose square root is to be found
 * @start: starting point of the search
 * @end: ending point of the search
 *
 * Return: integer square root of n
 */
int _sqrt_recursive_helper(int n, int start, int end)
{
	long int mid = (start + end) / 2;

	if (start > end)
	{
		return (-1);
	}
	if (mid * mid == n)
	{
		return (mid);
	}
	else if (mid * mid > n)
	{
		return (_sqrt_recursive_helper(n, start, mid - 1));
	}
	else
	{
		return (_sqrt_recursive_helper(n, mid + 1, end));
	}
}
