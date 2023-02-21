#include "main.h"

/**
 * main - Entry point for the program
 *
 * Description: prints the alphabet in lower case then a new line
 *
 * Return: 0 on success, non-zero on error.
 */
int main(void)
{
	int i;

	for (i = 'a'; i <= 'z'; i++)
	{
		_putchar(i);
	}

	_putchar('\n');

	return (0);
}
