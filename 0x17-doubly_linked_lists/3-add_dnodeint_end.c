#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a list_t list
 *
 * @head: Double pointer to the start of the list
 * @n: The int data to be added
 *
 * Return: The address of the new node added
 * OR NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *tail;

	if (head == NULL) /* null ptr */
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL) /* alloc fail */
		return (NULL);

	new_node->n	   = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*head == NULL) /* empty list */
		return (new_node);

	tail = *head;
	while (tail->next != NULL) /* traverse to end of list */
		tail = tail->next;

	tail->next = new_node; /* old tail next points to new_node */
	new_node->prev = tail; /* new_node prev points to old tail */
	tail = new_node; /* update the new_node to be the new tail */

	return (tail);
}
