#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes new node at a given position
 *
 * @head: Address of pointer to the start of the list
 * @index: Index of the list where new node will be added
 *
 * Return: Address of new node or NULL on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t	*curr_node = NULL; /* current ptr during traversal */
	listint_t	*prev_node = NULL; /* ptr of previous node in the list */
	unsigned int curr_node_index = 0; /* index of the current node in list */

	/* address of head ptr is NULL or list is empty (*head is NULL)*/
	if (head == NULL || *head == NULL)
		return (-1);

	/* traverse through the list to find node to delete */
	curr_node = *head;
	while (curr_node != NULL)
	{
		/* check if curr_node_index matches lookup index */
		if (curr_node_index == index)
		{
			if (curr_node_index == 0) /* make next node the head */
				*head = curr_node->next;

			if (curr_node_index > 0) /* for deletion at index > 0 */
				prev_node->next = curr_node->next;

			free(curr_node);/* delete node from memory */
			return (1);
		}
		prev_node = curr_node; /* set the curr node as the previous node */
		curr_node = curr_node->next; /* set the next node as the current node */
		curr_node_index++;			 /* increment the index */
	}

	/* if the lookup index is out of range */
	return (-1);
}
