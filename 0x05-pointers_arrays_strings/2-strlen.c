#include "main.h"

/**
 * _strlen - returns the length of a string
 *
 * @s: pointer to a
 *
 * Return: nothing
 */

int _strlen(char *s)
{
	int  count;
	char val;

	val   = *s;
	count = 0;

	while (val != '\0')
	{
		val = *(s + count);
		count++;
	}

	return (count - 1);
}
