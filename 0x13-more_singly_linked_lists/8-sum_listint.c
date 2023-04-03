#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data (n) of a listint_t linked list
 *
 * @head: Pointer to the start of the list
 *
 * Return: The sum of all data in the list
 * or 0 if empty
 */
int sum_listint(listint_t *head)
{
	listint_t	*curr_node		 = NULL;
	int sum_of_list_data = 0;

	/* head ptr is NULL (empty list) */
	if (head == NULL)
	{
		return (0);
	}

	/* traverse through the list */
	curr_node = head;
	while (curr_node != NULL)
	{
		/* add up data in current node to total*/
		sum_of_list_data += curr_node->n;
		/* set the next node as the current node */
		curr_node = curr_node->next;
	}

	/* if the search index is out of range */
	return (sum_of_list_data);
}
