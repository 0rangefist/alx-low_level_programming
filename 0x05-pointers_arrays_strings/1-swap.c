#include "main.h"

/**
 * swap_int -  uwaps the values of two integers
 *
 * @a: first pointer to an integer
 * @b: second pointer to an integer
 *
 * Return: nothing
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;

	*a = *b;
	*b = temp;
}
