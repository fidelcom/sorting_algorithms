#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *head;
	listint_t temp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		temp = head;
		temp->prev = NULL;
		temp->next = n;
		print_list(*list);
	}
}
