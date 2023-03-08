#include "main.h"

/**
 * _puts_recursion - prints a string, followed by a new line
 * @s: pointer to a string
 *
 * Return: void
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}
	/* print the val at current pointer */
	_putchar(*s);
	/* make a recursive call using next pointer */
	_puts_recursion(s + 1);
}
