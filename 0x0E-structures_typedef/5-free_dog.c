#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees memory of typedef dog_t
 *
 * @d: pointer to dog_t
 *
 * Description: This function frees the memory allocated for a dog structure,
 *              including the memory allocated for the name and owner strings.
 *
 * Return: void
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
