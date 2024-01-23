#include "sort.h"

void bitonic_compare(int *array, int i, int j, int dir)
{
	int swap;

	if ((dir == 1 && array[i] > array[j]) || (dir == 0 && array[i] < array[j]))
	{
		swap = array[i];
		array[i] = array[j];
		array[j] = swap;
	}
}


void bitonic_merge(int *array, size_t start, size_t length, int dir)
{
	int mid;
	size_t i;

	if (length > 1)
	{
		mid = length / 2;
		i = start;
		while (i < start + mid)
			bitonic_compare(array, i, i + mid, dir);

		bitonic_merge(array, start, mid, dir);
		bitonic_merge(array, start + mid, mid, dir);
	}
}


void create_bitonic(int *array, int start, int length, int dir)
{
	int mid;

	if (length > 1)
	{
		mid = length / 2;
		create_bitonic(array, start, mid, dir);
		create_bitonic(array, start + mid, mid, dir);
		bitonic_merge(array, start, length, dir);
	}
}

void bitonic_sort(int *array, size_t size)
{
	int start = 0;
	int mid = size / 2;
	int dir = 1;

	if (array == NULL || size < 2)
		return;
	create_bitonic(array, start, size, dir);
	bitonic_merge(array, start, size, dir);
	print_array(array, size);
}

