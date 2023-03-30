#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Adds a new node at the end of a list_t list
 *
 * @head: Address of the pointer to the start of the list
 * @str: The string data to be added
 *
 * Return: The address of the new node added
 * OR NULL on failure
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node  = NULL;
	list_t *curr_node = NULL;

	if (head == NULL || str == NULL)
		return (NULL);

	/* allocate memory for the new node */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL) /* on alloc fail */
		return (NULL);

	/* assign values to the elements of the new node */
	new_node->str = strdup(str);
	if (new_node->str == NULL) /*on alloc fail */
	{
		free(new_node);
		return (NULL);
	}
	new_node->len  = strlen(new_node->str);
	new_node->next = NULL; /* NULL because it is now the end node */

	/* if *head is NULL, the list is empty so we put in our new_node */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	/* For a non-empty list, we traverse to the end */
	curr_node = *head;
	while (curr_node->next != NULL)
	{
		curr_node = curr_node->next;
	}

	/* let the current end node point to our new_node */
	curr_node->next = new_node;

	return (new_node);
}
