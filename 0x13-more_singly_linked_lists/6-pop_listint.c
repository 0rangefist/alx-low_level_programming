#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list, and returns
 * the head node’s data (n)
 *
 * @head: Address of pointer to the start of the list
 *
 * Return: The data (n) of the head node
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *original_head = NULL;
	int original_head_data;

	/* address of head ptr or head ptr itself is NULL */
	if (head == NULL || *head == NULL)
	{
		return (0);
	}

	/* store data of head */
	original_head_data = (*head)->n;
	/* store the original head node */
	original_head = *head;
	/* make next node after head the new head */
	*head = (*head)->next;
	/* free the original head node */
	free(original_head);


	/*return the data in the deleted original head node */
	return (original_head_data);
}
