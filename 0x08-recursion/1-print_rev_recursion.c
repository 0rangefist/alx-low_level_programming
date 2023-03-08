#include "main.h"

/**
 * _print_rev_recursion - prints a string in reverse
 *
 * @s: pointer to a string
 *
 * Return: void
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0')
	{	/* return to calling fxn if val is null byte */
		return;
	}
	/* make a recursive call using next pointer */
	_print_rev_recursion(s + 1);

	/* after recursive call, print val at pointer */
	_putchar(*s);
}
