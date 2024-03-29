#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_node - Adds a new node at the beginning of a list_t list
 *
 * @head: Address of the pointer to the start of the list
 * @str: The string data to be added
 *
 * Return: The address of the new node added
 * OR NULL on failure
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node = NULL;

	if (head == NULL || str == NULL)
	{
		return (NULL);
	}

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL) /* on alloc fail */
	{
		return (NULL);
	}

	new_node->str = strdup(str);
	if (new_node->str == NULL) /*on alloc fail */
	{
		free(new_node);
		return (NULL);
	}

	new_node->len  = strlen(new_node->str);
	new_node->next = *head;
	*head		   = new_node;

	return (new_node);
}
