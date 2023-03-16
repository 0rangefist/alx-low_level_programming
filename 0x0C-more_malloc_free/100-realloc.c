#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: pointer to old memory to be reallocated
 * @old_size: bytes of memory the pointer points to
 * @new_size: bytes of memory the pointer should point to
 *
 * Return: pointer to the reallocated memory
 * or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int min_size;
	void		*new_ptr;

	if (new_size == old_size) /* no reallocation needed */
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{ /* free the prev memory of ptr if new_size equals 0 */
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL) /* go ahead & allocate new memory if no valid old memory */
	{
		ptr = malloc(new_size);
		if (ptr == NULL) /* if allocation fails */
			return (NULL);
		return (ptr);
	}

	/* allocate new memory*/
	new_ptr = malloc(new_size);
	if (new_ptr == NULL) /* if allocation fails */
		return (NULL);

	/* use min size between new_size and old_size */
	/* for copying values to new memory allocation */
	if (new_size < old_size)
		min_size = new_size;
	else
		min_size = old_size;

	/* copy content over from previous allocation */
	memcpy(new_ptr, ptr, min_size);

	/* free up old memory */
	free(ptr);
	
	return (new_ptr);
}
