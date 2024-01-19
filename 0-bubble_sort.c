#include "sort.h"

/**
 * bubble_sort - bubble sort
 * @array: array to sort
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, n_size = size;
	int tmp, swap;

	if (array == NULL || size < 2)
		return;

	while (n_size)
	{
		swap = 0;
		for (i = 0; i < n_size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
		n_size--;
		if (!swap)
			break;
	}
}
