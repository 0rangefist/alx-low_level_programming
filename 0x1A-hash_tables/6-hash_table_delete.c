#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long i;
	hash_node_t	 *curr, *next;

	if (ht == NULL) /* null table */
		return;

	/* iterate over table's array */
	for (i = 0; i < ht->size; i++)
	{
		curr = ht->array[i];
		/* free nodes in linked list */
		while (curr != NULL)
		{
			next = curr->next;
			free(curr->key);
			free(curr->value);
			free(curr);
			curr = next;
		}
	}

	/* free the table's array */
	free(ht->array);

	/* free the table */
	free(ht);
}
