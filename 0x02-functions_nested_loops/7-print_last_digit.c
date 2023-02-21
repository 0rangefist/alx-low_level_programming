#include "main.h"

/**
 * print_last_digit - prints last digit of a num
 * @n: character to check
 *  Return: int
 */

int print_last_digit(int n)
{
	if (n < 0)
	{
		return (-1 * (n % 10));
	}
	else
	{
		return (n % 10);
	}
}
