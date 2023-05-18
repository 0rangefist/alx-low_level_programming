#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t list
 *
 * @head: Pointer to the start of the list
 * @index: The index of the node, starting at 0
 *
 * Return: The nth node of the list
 * or NULL otherwise
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t	*curr_node		 = NULL;
	unsigned int curr_node_index = 0;

	/* head ptr is NULL */
	if (head == NULL)
	{
		return (NULL);
	}

	/* traverse through the list */
	curr_node = head;
	while (curr_node != NULL)
	{
		/* check if curr_node_index matches search index */
		if (curr_node_index == index)
		{
			return (curr_node);
		}
		/* set the next node as the current node */
		curr_node = curr_node->next;
		/* increment the index */
		curr_node_index++;
	}

	/* if the search index is out of range */
	return (NULL);
}

