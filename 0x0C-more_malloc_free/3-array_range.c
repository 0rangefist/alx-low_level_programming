#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * array_range - creates an array of integers from
 * min(inclusive) to max(inclusive)
 *
 * @min: first int of array
 * @max: last int of array
 *
 * Return: pointer to the array
 * or NULL on failure
 */
int *array_range(int min, int max)
{
	int *array;
	int	 num_of_elements;
	int	 val;
	int	 i;

	if (min > max) /* if values of min & max are switched */
		return (NULL);

	num_of_elements = (max - min) + 1;

	array = malloc(sizeof(*array) * num_of_elements);
	if (array == NULL) /* on allocation failure */
		return (NULL);

	/* input integers into array */
	for (val = min, i = 0; val <= max; val++, i++)
	{
		array[i] = val;
	}

	return (array);
}
