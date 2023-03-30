#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * list_len -  Returns the number of elements in a linked list_t list
 *
 * @h: Pointer to the start of the list
 *
 * Return: The number of nodes of the list
 */
size_t list_len(const list_t *h)
{
	size_t	num_of_nodes = 0;
	const list_t *curr_ptr = h;

	if (h == NULL)
	{
		/* there is nothing being pointed to */
		return (0);
	}

	while (curr_ptr != NULL)
	{
		num_of_nodes++;
		curr_ptr = curr_ptr->next;
	}

	return (num_of_nodes);
}
