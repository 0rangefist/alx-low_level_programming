#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - Prints all the elements of a listint_t list
 *
 * @h: Pointer to the start of the list
 *
 * Return: The number of nodes of the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t num_of_nodes = 0;

	if (h == NULL) /* empty list */
		return (num_of_nodes);

	while (h != NULL)
	{
		printf("%d\n", h->n);
		num_of_nodes++;
		h = h->next;
	}

	return (num_of_nodes);
}
