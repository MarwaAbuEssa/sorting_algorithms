
#include "sort.h"

void swap_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_ahead - Swap ahead a node in a listint_t doubly-linked
 * @list: head.
 * @tail: tail
 * @shaker: current swapping node of the cocktail shaker algo.
 */
void swap_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_behind - Swap behind a node in a listint_t doubly-linked
 * @list: header.
 * @tail: tail.
 * @shaker: current node of the cocktail shaker algo.
 */
void swap_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - cocktail shaker algorithm fordoubly-linked list. 
 * @list: header.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool check_shaken = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (check_shaken == false)
	{
		check_shaken = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				check_shaken = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				check_shaken = false;
			}
		}
	}
}
