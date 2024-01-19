#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list to sort
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *temp, *n_node;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;
	head = (*list)->next;
	n_node = head->next;
	while (head)
	{
		if (head->n < head->prev->n)
		{
			temp = head->prev;
			while (temp && (head->n < temp->n))
			{
				if (!(temp->prev))
				{
					temp->prev = head;
					head->prev->next = head->next;
					if (head->next)
						head->next->prev = head->prev;
					head->next = temp;
					head->prev = NULL;
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
				print_list(*list);
				temp = head->prev;
			}
		}
		head = n_node;
		head ? (n_node = head->next) : (n_node = NULL);
	}
}
