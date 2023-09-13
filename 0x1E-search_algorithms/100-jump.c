#include "search_algos.h"
/**
 * lin_search - searches for a value in an array with linear search
 *
 * @array: the array to be searched
 * @start: the start index to search
 * @end: the end index to search
 * @value: the value to search for
 *
 * Return: first index where value is found or
 * -1 if the value is not present
 */
int lin_search(int *array, int start, int end, int value)
{
	int i;

	for (i = start; i <= end; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value) /* target found */
			return (i);
	}
	return (-1); /* value wasn't found */
}

/**
 * jump_search - searches for a value in an array with jump search
 *
 * @array: the array to be searched
 * @size: the size of the array
 * @value: the value to search for
 *
 * Return: first index where value is found or
 * -1 if the value is not present
 */
int jump_search(int *array, size_t size, int value)
{
	int start_index;
	int end_index;
	int step	   = 0;
	int block_size = (int) sqrt(size);

	if (array == NULL || size == 0) /* empty array */
		return (-1);

	/* Jumping phase - done in jumps of block_size */
	while ((step < (int) size) && (array[step] < value))
	{
		printf("Value checked array[%d] = [%d]\n", step, array[step]);
		step = step + block_size;
	}

	/* Linear search phase - search from the start of the block */
	if (step - block_size < 0) /* start index of first block */
		start_index = 0;
	else /* start index for all but first block */
		start_index = step - block_size;
	if (step < (int) size) /* end index for all but last block */
		end_index = step;
	else /* end index for last block */
		end_index = (int) size - 1;

	printf("Value found between indexes [%d] and [%d]\n", start_index, step);
	return (lin_search(array, start_index, end_index, value));
}
