#include "main.h"

/**
 * reverse_array - everses the content of an array of integers
 *
 * @a: pointer to integer array
 * @n: number of elements of the array
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int temp;
	int i;

	for (i = 0; i < n - 1; i++)
	{
		temp         = a[i];
		a[i]         = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
