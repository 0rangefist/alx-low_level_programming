#include "search_algos.h"
/**
 * bin_search - searches for a value in an array with binary search
 *
 * @array: the array to be searched
 * @start: the start index to search
 * @end: the end index to search
 * @value: the value to search for
 *
 * Return: first index where value is found or
 * -1 if the value is not present
 */
int bin_search(int *array, int start, int end, int value)
{
	size_t i;
	size_t left_index  = start;
	size_t right_index = end;
	size_t middle_index;

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

/**
 * exponential_search - searches for a value in an array with
 * exponential search
 *
 * @array: the array to be searched
 * @size: the size of the array
 * @value: the value to search for
 *
 * Return: first index where value is found or
 * -1 if the value is not present
 */
int exponential_search(int *array, size_t size, int value)
{
	int start_index; /* start index for binary search */
	int end_index;	 /* end index for binary search */
	int bound = 1;		 /* bound for exponential search */

	if (array == NULL || size == 0) /* empty array */
		return (-1);

	/* Exponential growth phase */
	while ((bound < (int) size) && (array[bound] < value))
	{
		printf("Value checked array[%d] = [%d]\n", bound, array[bound]);
		bound		= bound * 2; /* double the bound */
	}

	/* Binary search phase */
	start_index = bound / 2; /* set the start index to previous bound */
	end_index	= (bound < (int) size) ? bound : (int) size - 1;

	printf("Value found between indexes [%d] and [%d]\n", start_index, end_index);
	return (bin_search(array, start_index, end_index, value));
}
