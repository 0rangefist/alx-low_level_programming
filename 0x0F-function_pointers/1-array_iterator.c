#include "function_pointers.h"

/**
 * array_iterator - executes a function given as a parameter on each element of
 * an array
 *
 * @array: array of elements
 * @size: size of the array
 * @action: pointer to function to use for execution
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	/* check that the pointers are not NULL & size is greater than 0*/
	if (array && action && (size > 0))
	{
		for (i = 0; i < size; i++)
		{
			action(array[i]);
		}
	}
}
