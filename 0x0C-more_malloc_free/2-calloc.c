#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _calloc - allocates memory for an array, using malloc
 * and sets the memory to 0
 *
 * @nmemb: number of elements of the array
 * @size: number of bytes of each element
 *
 * Return: pointer to the allocated memory
 * or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void		*ptr;
	unsigned int num_of_bytes = size * nmemb;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(num_of_bytes);
	if (ptr == NULL) /* on allocation failure */
		return (NULL);

	/* Set the allocated memory to zero */
	memset(ptr, 0, size * nmemb);

	return (ptr);
}
