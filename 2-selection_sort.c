#include "sort.h"

/**
  * selection_sort - sorts an array of integers in ascending order.
  * @array: a pointer to an integer array that needs to be sorted
  * @size: the size of the array.
  * Return: nothing
  */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	int swap;
	size_t j, l_elem;

	if (array == NULL || size < 2)
		return;

	while (i < size - 1)
	{
		l_elem = i;
		j = i + 1;
		while (j < size)
		{

			if (array[j] < array[l_elem])
				l_elem = j;
			j++;
		}
		if (l_elem != i)
		{
			swap = array[i];
			array[i] = array[l_elem];
			array[l_elem] = swap;
			print_array(array, size);
		}
		i++;
	}
}
