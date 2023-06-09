#include "hash_tables.h"
#include <stdio.h>
/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long i;
	hash_node_t	 *curr		  = NULL;
	int			  print_comma = 0;

	if (ht == NULL) /* empty table */
		return;		/* print nothing */

	printf("{"); /* print opening brace */
	/* loop through the table's array */
	for (i = 0; i < ht->size; i++)
	{
		/* traverse & print items in list */
		curr = ht->array[i];
		while (curr != NULL)
		{
			if (print_comma) /* flag to print appended comma */
				printf(", ");
			printf("'%s': '%s'", curr->key, curr->value);
			print_comma = 1; /* set flag for printing comma */
			curr		= curr->next;
		}
	}
	printf("}\n"); /* print closing brace & newline */
}
