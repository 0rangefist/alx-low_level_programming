#include "lists.h"

/**
 * free_listint - Frees the memory allocated to a listint_t list
 *
 * @head: Pointer to the start of the list
 *
 * Return: The address of the new node added
 * OR NULL on failure
 */
void free_listint(listint_t *head)
{
	listint_t *curr_node = head;

	/* check if head is NULL, so we dont waste time with empty list */
	if (head == NULL)
	{
		return;
	}

	/* traverse through the entire list & free each node */
	while (head != NULL)
	{
		curr_node = head;
		head	  = head->next;
		free(curr_node);
	}
}
