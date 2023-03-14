#include "main.h"
#include <stdlib.h>

/**
 * create_array -  creates an array of chars, and
 * initializes it with a specific char
 *
 * @size: size of the array to be created
 * @c: character used for the initialization
 *
 * Return: pointer to the array, or NULL on failure
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	char *array_ptr;

	if (size == 0)
	{
		return (0);
	}

	array = malloc(sizeof(char) * size);
	if (array == 0) /* check if null and return null */
	{
		return (0);
	}

	for (array_ptr = array; array_ptr < array + size; array_ptr++)
	{
		*array_ptr = c;
	}

	return (array);
}
