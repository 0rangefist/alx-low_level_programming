#include "lists.h"
#include <stdio.h>

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 *
 * @head: Double pointer to the start of the list
 * @n: int data to add to the list
 *
 * Return: The address of the new node added
 * OR NULL on failure
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	if (head == NULL) /* null ptr */
		return (NULL);

	/* create the node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL) /* alloc fail */
		return (NULL);
	new_node->n	   = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL) /* if not an empty list */
		(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}
