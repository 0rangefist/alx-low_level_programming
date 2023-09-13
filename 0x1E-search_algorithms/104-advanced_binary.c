#include "search_algos.h"
/**
 * bin_recur - recursive binary search for the leftmost value
 *
 * @array: the array to be searched
 * @left_index: the left index of the current search range
 * @right_index: the right index of the current search range
 * @value: the value to search for
 *
 * Return: first index where value is found or
 * -1 if the value is not present
 */
int bin_recur(int *array, size_t left_index, size_t right_index, int value)
{
	size_t i;
	size_t middle_index;
	int	   leftmost = -1;

	if (left_index > right_index) return (-1);

	middle_index = left_index + (right_index - left_index) / 2;

	printf("Searching in array: ");
	for (i = left_index; i <= right_index; i++)
	{
		if (i == right_index)
			printf("%d", array[i]); /* last value */
		else
			printf("%d, ", array[i]);
	}
	printf("\n");

	if (array[middle_index] < value)
		return bin_recur(array, middle_index + 1, right_index, value);
	else if (array[middle_index] > value)
		return bin_recur(array, left_index, middle_index, value);
	else
	{
		leftmost = bin_recur(array, left_index, middle_index - 1, value);
		return (leftmost != -1) ? leftmost : (int) middle_index;
	}
}

/**
 * advanced_binary - searches for a value in an array with advanced
 * binary search (finds the leftmost, if repeated values are present)
 *
 * @array: the array to be searched
 * @size: the size of the array
 * @value: the value to search for
 *
 * Return: first index where value is found or
 * -1 if the value is not present
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0) return (-1);

	return bin_recur(array, 0, size - 1, value);
}
