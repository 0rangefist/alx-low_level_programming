#include "lists.h"

/**
 * free_listint2 - Frees the memory allocated to a listint_t list
 * & sets head to NULL
 *
 * @head: Address of pointer to the start of the list
 *
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *curr_node = NULL;

	/* address of head ptr is NULL */
	if (head == NULL || *head == NULL)
	{
		return;
	}

	/* traverse through the list & free each node */
	while (*head != NULL)
	{
		curr_node = *head;		   /* Set current node head */
		*head	  = (*head)->next; /* Move head pointer to next node */
		free(curr_node);		   /* Free current node */
	}
}
