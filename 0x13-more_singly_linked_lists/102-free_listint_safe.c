#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list
 *
 * @h: Double pointer to the start of the list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	/* we use the tortoise & hare algorithm to detect a loop */
	listint_t *tortoise = *h;
	listint_t *hare		= *h;
	listint_t *temp_node = NULL;
	size_t list_size = 0;

	if (h == NULL || *h == NULL) /* there is no list, so no loop*/
		return (0);

	/* traverse through the loop with both tortoies & hare */
	/* hare is the fastest so will reach end of list if no loop */
	/* thus we check for tortoise && tortoise->next being NULL */
	while (hare != NULL && hare->next != NULL)
	{
		temp_node = tortoise;
		tortoise = tortoise->next;
		hare	 = (hare->next)->next;
		free(temp_node);
		list_size++;
		if (tortoise == hare) /* if tortoise == hare, loop detected */
		{
			/*reset tortoise to head but leave hare the same*/
			tortoise = *h;
			while (tortoise != hare)
			{ /* increment tortoise & hare till they meet */
				temp_node = hare;
				tortoise = tortoise->next;
				hare	 = hare->next;
				free(temp_node);
				list_size++;
			}
			/* back to start of cycle/loop */
			return (list_size);
		}
	}
	/* return size of freed list without loop */
	return (list_size);

}
