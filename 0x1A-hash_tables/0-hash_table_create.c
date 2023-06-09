#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table with a specified size
 * @size: The size of the hash table
 *
 * Return: A pointer to the created hash table, or NULL if an error occurred
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t	 *table = NULL;
	unsigned long int i		= 0;

	if (size == 0) /* can't create table */
		return (NULL);

	/* allocate memory for the table */
	table = malloc(sizeof(hash_table_t));
	if (table == NULL) /* alloc fail */
		return (NULL);

	/* allocate memory for array of node pointers in the table */
	table->array = malloc(size * sizeof(hash_node_t *));
	if (table->array == NULL) /* alloc fail */
		return (NULL);

	for (i = 0; i < size; i++) /* initialize all nodes to NULL */
		table->array[i] = NULL;

	/* set value of size */
	table->size = size;

	return (table);
}
