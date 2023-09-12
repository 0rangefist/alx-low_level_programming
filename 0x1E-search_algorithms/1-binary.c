#include "search_algos.h"
/**
 * binary_search - searches for a value in an array with binary search
 *
 * @array: the array to be searched
 * @size: the size of the array
 * @value: the value to search for
 *
 * Return: first index where value is found or
 * -1 if the value is not present
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i;
	size_t left_index  = 0;
	size_t right_index = size - 1;
	size_t middle_index;

	if (array == NULL)
		return (-1);

	while (left_index <= right_index)
	{
		printf("Searching in array: ");
		for (i = left_index; i <= right_index; i++)
		{
			if (i == right_index)
				printf("%d", array[i]); /* last value */
			else
				printf("%d, ", array[i]);
		}
		printf("\n");

		middle_index = left_index + (right_index - left_index) / 2;
		if (array[middle_index] < value) /* search upper half */
			left_index = middle_index + 1;
		else if (array[middle_index] > value) /* search lower half */
			right_index = middle_index - 1;
		else /* the middle index has the target value */
			return (middle_index);
	}

	return (-1); /* value wasn't found */
}
