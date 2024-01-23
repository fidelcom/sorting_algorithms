#include "sort.h"

void create_bitonic(int *array, int start, int length, int flag)
{
	int mid;

	if (length > 1)
	{
		mid = length / 2;
		create_bitonic(array, start, mid, 1);
		create_bitonic(array, start + mid, mid, 0);
		bitonic_merge(array, start, length, flag);
	}
}

void bitonic_merge(int *array, int start, int length, int flag)
{
	int mid, i;

	if (length > 1)
	{
		mid = length / 2;
		i = start;
		while (i < start + mid)
		{
			compare_and_swap(array, i, i + mid, flag);
			i++;
		}
		bitonic_merge(array, start, mid, flag);
		bitonic_merge(array, start + mid, mid, flag);
	}
}

	function compare_and_swap(array, index1, index2, flag)
if flag is true (or 1)
	if array[index1] > array[index2]
	swap array[index1] and array[index2]
	else
	if array[index1] < array[index2]
	swap array[index1] and array[index2]
void bitonic_sort(int *array, size_t size)
{
	size_t i;

	while (i < size)
	{
		if (array[i] < array[size - 1])
		{
			print_array(array, size);
		}

		if (array[size - 1] < array[i])
			print_array(array, size);
		i++;
	}
