#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - creates a new dog
 *
 * @name: string that holds dog's name
 * @age: float that holds dog's age
 * @owner: string that holds owner's name
 *
 * Return: a new dog or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	/* allocate memory for a new dog*/
	dog = malloc(sizeof(*dog));
	if (dog == NULL) /* on allocation failure */
	{
		return (NULL);
	}

	/* allocate memory for the dog->name field */
	dog->name = malloc(sizeof(char) * (strlen(name) + 1));
	if (dog->name == NULL) /* on allocation failure */
	{
		free(dog);
		return (NULL);
	}

	/* allocate memory for the dog->owner field */
	dog->owner = malloc(sizeof(char) * (strlen(owner) + 1));
	if (dog->owner == NULL) /* on allocation failure */
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	/* copy the values of name and owner */
	/* into dog->name and dog->owner fields*/
	strcpy(dog->name, name);
	strcpy(dog->owner, owner);

	/* regular assignment of age value */
	dog->age = age;

	return (dog);
}
