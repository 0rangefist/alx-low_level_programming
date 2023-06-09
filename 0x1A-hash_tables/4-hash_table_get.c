#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - Retrieves a value associated with a key in a hash table
 * @ht: The hash table to retrieve the value from
 * @key: The key to search for
 *
 * Return: The value associated with the key, or NULL if key not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t	 *curr = NULL;

	if (ht == NULL || key == NULL || *key == '\0') /* empty table/key */
		return (NULL);

	/* get the index for the key using the hash function */
	index = key_index((const unsigned char *)key, ht->size);

	/* retrieve item at the index */
	curr = ht->array[index];

	if (curr == NULL) /* no item at index */
		return (NULL);

	/* if index has item(s) */
	while (curr != NULL)
	{ /* traverse list for a matching key */
		if (strcmp(key, curr->key) == 0) /* match */
			return (curr->value);
		curr = curr->next;
	}

	/* no item with search key found */
	return (NULL);
}
