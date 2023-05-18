#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts new node at a given position
 *
 * @h: Address of pointer to the start of the list
 * @idx: Index of the list where new node will be added
 * @n: Data of new node to be added
 *
 * Return: Address of new node or NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t	*new_node		 = NULL; /* ptr of new node to be inserted */
	dlistint_t	*curr_node		 = NULL; /* current ptr during traversal */
	dlistint_t	*prev_node		 = NULL; /* ptr of previous node in the list */
	unsigned int curr_node_index = 0;	 /* index of the current node in list */

	if (h == NULL) /* null ptr */
		return (NULL);
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL) /* on alloc fail */
		return (NULL);
	new_node->n = n;		   /* set data variable of node */
	if (*h == NULL && idx > 0) /* idx out of bounds for empty list */
		return (NULL);
	if (idx == 0)
	{							   /* for insertion at unique case of index 0 */
		new_node->next = *h;	   /* new node points to old head */
		new_node->prev = NULL;	   /* new node has no prev node */
		if (*h != NULL)			   /* not an empty list */
			(*h)->prev = new_node; /* old head points back to new node */
		*h = new_node;			   /* update head pointer to new node */
		return (new_node);
	}
	for (curr_node = *h; curr_node != NULL; curr_node_index++)
	{ /* traverse through the list */
		if (curr_node_index == idx)
		{ /* check if curr_node_index matches lookup index */
			new_node->next	= curr_node;
			new_node->prev	= curr_node->prev;
			prev_node->next = new_node;
			curr_node->prev = new_node;
			return (new_node);
		}
		prev_node = curr_node; /* set the curr node as the previous node */
		curr_node = curr_node->next; /* set the next node as the current node */
	}
	free(new_node); /* if the lookup index is out of range */
	return (NULL);
}
