#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a list_t list
 *
 * @head: Address of the pointer to the start of the list
 * @n: The int data to be added
 *
 * Return: The address of the new node added
 * OR NULL on failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node  = NULL;
	listint_t *curr_node = NULL;

	if (head == NULL) /* address of head ptr is NULL */
		return (NULL);

	/* allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL) /* on alloc fail */
		return (NULL);

	/* assign int values to element of the new node */
	new_node->n = n;
	/* let new node be end node by making it's next point to NULL */
	new_node->next = NULL;

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
