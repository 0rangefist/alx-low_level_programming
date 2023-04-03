#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list
 *
 * @head: Address of the pointer to the start of the list
 * @n: The int data to be added
 *
 * Return: The address of the new node added
 * OR NULL on failure
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = NULL;

	if (head == NULL)
	{ /* head a of the list is a NULL pointer */
		return (NULL);
	}

	/* Allocate memory for new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL) /* on alloc fail */
	{
		return (NULL);
	}
	/* Set the value of the new node */
	new_node->n = n;
	/* Let new node's next point to head */
	new_node->next = *head;
	/* Let the new head point to the new node */
	*head = new_node;

	return (new_node);
}
