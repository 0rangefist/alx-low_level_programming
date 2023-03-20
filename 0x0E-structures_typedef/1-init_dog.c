#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - initializes a variable of type struct dog
 *
 * @d: pointer to dog struct to be initialized
 * @name: string that holds dog's name
 * @age: float that holds dog's age
 * @owner: string that holds owner's name
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{ /* if d doesn't point to valid memory addresses */
	if (d != NULL)
	{
		d->name	 = name;
		d->age	 = age;
		d->owner = owner;
	}
}
