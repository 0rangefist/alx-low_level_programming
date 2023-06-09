#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - Inserts or updates an element in a hash table
 * @ht: The hash table to insert or update the element in
 * @key: The key of the element
 * @value: The value of the element
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long index;
	hash_node_t	 *new_node = NULL;
	hash_node_t	 *curr	   = NULL;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL) /*null ptr*/
		return (0);

	/* get the hash index */
	index = key_index((const unsigned char *) key, ht->size);
	if (ht->array[index] != NULL)
	{ /* if an item is already at the hash index */
		curr = ht->array[index];
		while (curr != NULL)
		{ /* traverse list for a matching key & overwirte the value */
			if (strcmp(key, curr->key) == 0) /* if match */
			{
				free(curr->value);			 /* free previous value */
				curr->value = strdup(value); /* replace the value */
				return (1);
			}
			curr = curr->next;
		}
	}
	/* if null at index(empty bucket) or no matching key in list(collision) */
	new_node = malloc(sizeof(hash_node_t)); /* create a new_node */
	if (new_node == NULL)					/* alloc fail */
		return (0);
	/* set key & value of the new_node */
	new_node->key	= strdup(key);
	new_node->value = strdup(value);
	/* add new_node to head of list in the table */
	new_node->next	 = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}

