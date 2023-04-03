#include "lists.h"

/**
 * print_listint - Prints all the elements of a listint_t list
 *
 * @h: Pointer to the start of the list
 *
 * Return: The number of nodes of the list
 */
size_t print_listint(const listint_t *h)
{
	size_t		  num_of_nodes = 0;
	const listint_t *curr_ptr	  = h;

	if (h == NULL)
	{
		/* head a of the list is a NULL pointer */
		return (0);
	}

	while (curr_ptr != NULL)
	{
		num_of_nodes++;
		printf("%d\n", curr_ptr->n);
		curr_ptr = curr_ptr->next;
	}

	return (num_of_nodes);
}
