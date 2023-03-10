#include "main.h"

/**
 * _isdigit - checks for a digit (0 through 9)t
 *
 * @c: the character to check.
 *
 * Return: 1 on success, 0 otherwise.
 */

int _isdigit(int c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
		|| c == '6' || c == '7' || c == '8' || c == '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
