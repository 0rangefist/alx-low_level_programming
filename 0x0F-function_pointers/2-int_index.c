#include "function_pointers.h"

/**
 * int_index - searches for an integer
 *
 * @array: array of elements
 * @size: size of the array
 * @cmp: pointer to function to use for comparison
 *
 * Return: the index of the first element
 * for which the function cmp does not return 0.
 * Otherwise, return -1 if no element matches,
 * or size is less/equal to 0;
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	/* check that the pointers are not NULL & size is greater than 0*/
	if (array && cmp && (size > 0))
	{
		for (i = 0; i < size; i++)
		{
			/* check for the first element that isn't 0 */
			if (cmp(array[i]) != 0)
			{
				/* return the index of that element */
				return (i);
			}
		}
	}

	/* return -1 if no match of size <=0*/
	return (-1);
}
