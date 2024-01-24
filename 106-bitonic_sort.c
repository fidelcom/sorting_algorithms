#include "sort.h"

/**
 * bitonic_compare - Swap two integers in an array.
 * @i: The first integer to swap.
 * @j: The second integer to swap.
 */
void bitonic_compare(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @dir: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char dir)
{
	size_t i, mid = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + mid; i++)
		{
			if ((dir == UP && array[i] > array[i + mid]) ||
			    (dir == DOWN && array[i] < array[i + mid]))
				bitonic_compare(array + i, array + i + mid);
		}
		bitonic_merge(array, size, start, mid, dir);
		bitonic_merge(array, size, start + mid, mid, dir);
	}
}

/**
 * create_bitonic - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @dir: The direction to sort the bitonic sequence block in.
 */
void create_bitonic(int *array, size_t size, size_t start, size_t seq,
		char dir)
{
	size_t mid = seq / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		create_bitonic(array, size, start, mid, UP);
		create_bitonic(array, size, start + mid, mid, DOWN);
		bitonic_merge(array, size, start, seq, dir);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
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
	if (array == NULL || size < 2)
		return;

	create_bitonic(array, size, 0, size, UP);
}
