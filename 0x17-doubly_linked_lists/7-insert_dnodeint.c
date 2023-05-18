#include "lists.h"

/**
 * create_node - Creates and initializes a new node
 *
 * @n: Data of new node to be added
 *
 * Return: Pointer to the new node or NULL on failure
 */
dlistint_t *create_node(int n)
{
	dlistint_t *new_node = NULL; /* ptr of new node to be created */

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL) /* on alloc fail */
		return (NULL);
	new_node->n	   = n;	   /* set data variable of node */
	new_node->next = NULL; /* set next pointer of node */
	new_node->prev = NULL; /* set prev pointer of node */

	return (new_node);
}

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

	if (h == NULL || (*h == NULL && idx > 0)) /* null ptr/idx out of bounds */
		return (NULL);
	new_node = create_node(n); /* create and initialize new node */
	if (new_node == NULL)	   /* on alloc fail */
		return (NULL);
	if (idx == 0)
	{							   /* for insertion at unique case of index 0 */
		new_node->next = *h;	   /* new node points to old head */
		if (*h != NULL)			   /* not an empty list */
			(*h)->prev = new_node; /* old head points back to new node */
		*h = new_node;			   /* update head pointer to new node */
		return (new_node);
	}
	for (curr_node = *h; curr_node != NULL; curr_node_index++)
	{ /* traverse through the list using a for loop */
		if (curr_node_index == idx)
		{ /* check if curr_node_index matches lookup index */
			new_node->next	= curr_node; /* new node points to current node */
			new_node->prev	= curr_node->prev; /*new node points back to prev*/
			prev_node->next = new_node; /* previous node points to new node */
			curr_node->prev = new_node; /* current node points back to new */
			return (new_node);
		}
		prev_node = curr_node; /* set the curr node as the previous node */
		curr_node = curr_node->next; /* set the next node as the current node */
	}
	if (curr_node_index == idx) /* check if index is equal to list length */
	{
		prev_node->next = new_node;	 /* previous node points to new node */
		new_node->prev	= prev_node; /* new node points back to previous node */
		return (new_node);
	}
	free(new_node);
	return (NULL); /* if the lookup index is out of range */
}
