#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes node at a given position
 *
 * @head: Address of pointer to the start of the list
 * @index: Index of the list where new node will be added
 *
 * Return: 1 on success or -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t	*temp_node		 = NULL; /* temp storage node */
	dlistint_t	*curr_node		 = NULL; /* current ptr during traversal */
	dlistint_t	*prev_node		 = NULL; /* ptr of previous node in the list */
	unsigned int curr_node_index = 0;	 /* index of the current node in list */

	if (head == NULL || *head == NULL) /* null ptr or empty list */
		return (-1);

	if (index == 0)
	{
		if ((*head)->next == NULL) /* only one node in list */
		{
			free(*head);
			*head = NULL;
		}
		else /* more than one node in list */
		{
			temp_node	  = *head;		   /* temporarily save head node*/
			*head		  = (*head)->next; /* make next node the head */
			(*head)->prev = NULL;		   /* point new head's prev to NULL */
			free(temp_node);			   /* free original head node */
		}
		return (1); /* successfully deleted node */
	}
	for (curr_node = *head; curr_node != NULL; curr_node_index++)
	{ /* traverse through the list using a for loop */
		if (curr_node_index == index)
		{ /* check if curr_node_index matches lookup index */
			prev_node->next = curr_node->next;
			if (curr_node->next != NULL) /* deleting any but last node */
				curr_node->next->prev = prev_node;
			free(curr_node);
			return (1); /* successfully freed node */
		}
		prev_node = curr_node; /* set the curr node as the previous node */
		curr_node = curr_node->next; /* set the next node as the current node */
	}
	return (-1); /* if the lookup index is out of range */
}
