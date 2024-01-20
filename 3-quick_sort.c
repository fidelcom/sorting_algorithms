#include "sort.h"

/**
  * lomuto_partition - lomuto scheme for partitioning arrays.
  * @array: array
  * @low: starting index
  * @high: ending index
  * @size: size of the array
  * Return: the final partition index
  */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j, swap = 0;

	j = low;
	while (j <= high)
	{
		if (array[j] < pivot)
		{
			swap = array[i];
			array[i] = array[j];
			array[j] = swap;

			if (swap != array[i])
				print_array(array, size);

			i++;
		}
		j++;
	}
	swap = array[i];
	array[i] = array[high];
	array[high] = swap;

	if (swap != array[i])
		print_array(array, size);

	return (i);
}

/**
  * quick_sort_helper - Implement the quicksort algorithm through recursion
  * @array: array
  * @low: starting index of array
  * @high: ending index of the array
  * @size: size of the array
  * Return: nothing
  */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int l_p = 0;

	if (low < high)
	{
		l_p = lomuto_partition(array, low, high, size);
		quick_sort_helper(array, low, l_p - 1, size);
		quick_sort_helper(array, l_p + 1, high, size);
	}
}

/**
  * quick_sort - Sort an array of integers in ascending
  *	order using the quicksort algorithm
  * @array: array to sort
  * @size: size of the array
  * Return: nothing
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
