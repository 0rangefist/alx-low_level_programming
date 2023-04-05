#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list
 *
 * @h: Pointer to the start of the list
 *
 * Return: The size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t		num_of_nodes = 0;
	listint_t  *curr_node = NULL, *next_node = NULL;
	listint_t **previously_visited = NULL;
	size_t		i;

	if (h == NULL) /* head of the list is a NULL pointer */
		return (0);
	curr_node = *h;
	while (curr_node != NULL)
	{
		/* check if current node has been visited previously */
		for (i = 0; i < num_of_nodes; i++)
		{
			if (curr_node == previously_visited[i])
			{
				free(previously_visited);
				*h = NULL; /* set the head to NULL */
				return (num_of_nodes);
			}
		}
		next_node = curr_node->next;
		/* allocate memory for the visited node */
		previously_visited = malloc((num_of_nodes + 1) * sizeof(listint_t *));
		if (previously_visited == NULL) /* on alloc fail */
			exit(98);
		previously_visited[num_of_nodes] = curr_node; /* save the curr visited node*/
		num_of_nodes++;		   /* increment the number of nodes by 1 */
		curr_node = next_node; /* set the next node as curr node */
	}
	curr_node = *h;
	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		free(curr_node); /* free the current node */
		curr_node = next_node;
	}
	free(previously_visited);
	*h = NULL; /* set the head to NULL */
	return (num_of_nodes);
}
