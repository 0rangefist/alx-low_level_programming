#include "search_algos.h"
/**
 * linear_search - searches for a value in an array with linear search
 *
 * @array: the array to be searched
 * @size: the size of the array
 * @value: the value to search for
 *
 * Return: first index where value is found or
 * -1 if the value is not present
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (value == array[i]) /* value found at i */
			return (i);
	}

	return (-1); /* value wasn't found */
}
