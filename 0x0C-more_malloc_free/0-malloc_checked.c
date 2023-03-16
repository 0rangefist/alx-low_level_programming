#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked -  allocates memory using malloc
 *
 * @b: number of bytes of memory to allocate
 *
 * Return: pointer to the allocated memory
 * or exit with status of 98 on failure
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL) /* on allocation failure */
	{
		exit(98);
	}
	return (ptr);
}
