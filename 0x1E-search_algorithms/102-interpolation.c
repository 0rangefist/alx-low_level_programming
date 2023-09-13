#include "search_algos.h"
/**
 * interpolation_search - searches for a value in an array with
 * interpolation search
 *
 * @array: the array to be searched
 * @size: the size of the array
 * @value: the value to search for
 *
 * Return: first index where value is found or
 * -1 if the value is not present
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t left_index  = 0;
	size_t right_index = size - 1;
	size_t position;

	if (array == NULL) /* empty array */
		return (-1);

	while (left_index <= right_index)
	{
		/* postion estimated by linear interpolation: x = (y - c) ÷ m */
		position = left_index
				   + ((value - array[left_index]) * (right_index - left_index))
						 / (array[right_index] - array[left_index]);
		if (position >= size)
		{
			printf("Value checked array[%ld] is out of range\n", position);
			break;
		}
		printf("Value checked array[%ld] = [%d]\n", position, array[position]);

		if (array[position] < value) /* search right subarray */
			left_index = position + 1;
		else if (array[position] > value) /* search left subarray */
			right_index = position - 1;
		else /* found the target value */
			return (position);
	}

	return (-1); /* value wasn't found */
}
