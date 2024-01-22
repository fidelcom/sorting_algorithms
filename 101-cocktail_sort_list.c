#include "sort.h"
/**
 * swap_both_side - swaps both
 * @temp: first node to swap
 * @head: second node to swap
 * @list: list to set null or not
 */
void swap_both_side(listint_t *temp, listint_t *head, listint_t **list)
{
	if (!(temp->prev))
	{
		temp->next = head->next;
		if (head->next)
			head->next->prev = temp;
		head->next = temp;
		head->prev = NULL;
		temp->prev = head;
		*list = head;
	}
	else
	{
		head->prev->next = head->next;
		if (head->next)
			head->next->prev = head->prev;
		temp->prev->next = head;
		head->prev = temp->prev;
		temp->prev = head;
		head->next = temp;
	}
}

/**
 * cocktail_sort_list - inserts right unsorted side into left sorted side
 * @list: doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *n_node;
	int swapped;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;

	head = (*list);
	do {
		swapped = 0;
		while (head->next)
		{
			n_node = head->next;
			if (n_node && head->n > n_node->n)
			{
				swap_both_side(head, n_node, list);
				swapped = 1;
				print_list((*list));
			}
			else
				head = head->next;
		}
		head = head->prev;
		while (head->prev)
		{
			n_node = head->prev;
			if (n_node && head->n < n_node->n)
			{
				swap_both_side(n_node, head, list);
				swapped = 1;
				print_list((*list));
			}
			else
				head = head->prev;
		}
		head = head->next;
	} while (swapped);
}
