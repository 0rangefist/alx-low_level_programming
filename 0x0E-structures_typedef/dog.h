#ifndef DOG_STRUCT_H
#define DOG_STRUCT_H

/**
 * struct dog - custom dog struct
 *
 * @name: string that holds the name of the dog
 * @age: float that holds the age of the dog
 * @owner: string that holds the owners name
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_STRUCT_H */
