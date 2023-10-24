#include "sort.h"

/**
 * swap_two - Swap two nodes in doubly-linked list.
 * @header:  head
 * @node1: first node to swap.
 * @node2: second node to swap.
 */
void swap_two(listint_t **header, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*header = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - insertion sort a doubly linked list
 * @list: pointer to the head .
 * Description: Prints list .
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *inode, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (inode = (*list)->next; inode != NULL; inode = tmp)
	{
		tmp = inode->next;
		insert = inode->prev;
		while (insert != NULL && inode->n < insert->n)
		{
			swap_two(list, &insert, inode);
			print_list((const listint_t *)*list);
		}
	}
}
