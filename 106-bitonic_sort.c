#include "sort.h"

/**
 * bitonic_compare - compares and swaps two integers in an array
 * @array: array
 * @i: first integer
 * @j: second integer
 * @dir: order of swap
 */
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

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: array
 * @start: The starting index of the sequence in array to sort
 * @size: The size of the array.
 * @dir: The direction to sort in
 */
void bitonic_merge(int *array, size_t start, size_t size, int dir)
{
	size_t i, mid;

	if (size > 1)
	{
		mid = size / 2;
		i = start;
		while (i < start + mid)
		{
			bitonic_compare(array, i, i + mid, dir);
			i++;
		}
		bitonic_merge(array, start, mid, dir);
		bitonic_merge(array, start + mid, mid, dir);
	}
}

/**
 * create_bitonic - Convert an array of integers into a bitonic sequence.
 * @array: array
 * @start: The starting index of a block of the building bitonic sequence
 * @size: size of the array
 * @dir: The direction to sort the bitonic sequence block in
 */
void create_bitonic(int *array, size_t start, size_t size, int dir)
{
	size_t mid;

	if (size > 1)
	{
		mid = size / 2;
		print_array(array + start, mid);
		create_bitonic(array, start, mid, 1);
		create_bitonic(array, start + mid, mid, 0);
		bitonic_merge(array, start, size, dir);
		print_array(array + start, mid);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	int dir = 1;

	if (array == NULL || size < 2)
		return;
	create_bitonic(array, 0, size, dir);
	print_array(array, size);
}
