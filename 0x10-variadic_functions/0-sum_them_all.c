#include "variadic_functions.h"

/**
 * sum_them_all - sums a list of arbitrarily long integers
 *
 * @n: user determined number of arguments to sum
 *
 * Return: returns the factorial as an int
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list arg_list_ptr;
	unsigned int i;
	int	sum = 0;

	if (n == 0) /* check if n == 0 */
		return (0);

	/* initialize the arg_list_ptr to point to */
	/* point to the start of the user entered list */
	va_start(arg_list_ptr, n);

	for (i = 0; i < n; i++)
	{
		sum = sum + va_arg(arg_list_ptr, int);
	}

	return (sum);
}
