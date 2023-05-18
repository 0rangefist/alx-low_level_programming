#include "lists.h"
#include <stdio.h>

/**
 * dlistint_len - returns the number of elements in a linked
 *
 * @h: Pointer to the start of the list
 *
 * Return: length of the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t num_of_nodes = 0;

	if (h == NULL) /* empty list */
		return (num_of_nodes);

	while (h != NULL)
	{
		num_of_nodes++;
		h = h->next;
	}

	return (num_of_nodes);
}
