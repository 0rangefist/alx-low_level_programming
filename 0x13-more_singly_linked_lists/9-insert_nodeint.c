#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts new node at a given position
 *
 * @head: Address of pointer to the start of the list
 * @idx: Index of the list where new node will be added
 * @n: Data of new node to be added
 *
 * Return: Address of new node or NULL on failure
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node	 = NULL; /* ptr of new node to be inserted */
	listint_t *curr_node = NULL; /* current ptr during traversal */
	listint_t *prev_node = NULL; /* ptr of previous node in the list */
	unsigned int curr_node_index = 0; /* index of the current node in the list */

	if (head == NULL) /* address of head ptr is NULL */
		return (NULL);

	/* allocate memory for the new node */
	new_node = malloc(sizeof(new_node));
	if (new_node == NULL) /* on alloc fail */
		return (NULL);

	new_node->n = n; /* set data variable of node */

	if (*head == NULL) /* if head ptr is NULL (list is empty)*/
	{
		new_node->next = NULL;
		return (new_node);
	}

	/* traverse through the list */
	curr_node = *head;
	while (curr_node != NULL)
	{
		/* check if curr_node_index matches lookup index */
		if (curr_node_index == idx)
		{
			new_node->next = curr_node;
			if (curr_node_index > 0) /* for insertions after index 0 */
				prev_node->next = new_node;
			return (new_node);
		}
		prev_node = curr_node; /* set the curr node as the previous node */
		curr_node = curr_node->next; /* set the next node as the current node */
		curr_node_index++; /* increment the index */
	}

	/* if the lookup index is out of range */
	return (NULL);
}
