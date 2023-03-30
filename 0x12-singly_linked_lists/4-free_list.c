#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * free_list -  Frees the memory allocated to a list_t list
 *
 * @head: Address of the pointer to the start of the list
 *
 * Return: The address of the new node added
 * OR NULL on failure
 */
void free_list(list_t *head)
{
	list_t *curr_node = head;

	/* check if head is NULL, so we don't deref a NULL ptr */
	if (head == NULL)
	{
		return;
	}

	/* we free the str element, then the node itself */
	/* traverse through the entire list */
	while (head != NULL)
	{
		curr_node = head;
		head	  = head->next;
		free(curr_node->str);
		free(curr_node);
	}
}
