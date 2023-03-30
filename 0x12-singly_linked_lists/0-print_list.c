#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_list - Prints all the elements of a list_t list
 *
 * @h: Pointer to the start of the list
 *
 * Return: The number of nodes of the list
 */
size_t print_list(const list_t *h)
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
		if (curr_ptr->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] %s\n", curr_ptr->len, curr_ptr->str);
		}
		curr_ptr = curr_ptr->next;
	}

	return (num_of_nodes);
}
