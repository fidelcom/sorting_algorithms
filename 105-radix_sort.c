#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int position,
		int *new_array);
/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max = array[0];
	int i = 1;

	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *			in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @position: The significant digit to sort on.
 * @new_array: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int position, int *new_array)
{
	size_t i;
	int count[10];

	i = 0;
	while (i < 10)
	{
		count[i] = 0;
		i++;
	}

	i = 0;
	while (i < size)
	{
		count[(array[i] / position) % 10]++;
		i++;
	}

	i = 1;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}
	i = size - 1;
	while ((int)i >= 0)
	{
		new_array[count[(array[i] / position) % 10] - 1] = array[i];
		count[(array[i] / position) % 10]--;
		i--;
	}
	i = 0;
	while (i < size)
	{
		array[i] = new_array[i];
		i++;
	}
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int position;
	int *new_array;

	if (array == NULL || size < 2)
		return;

	new_array = malloc(sizeof(int) * size);
	if (new_array == NULL)
		return;

	position = 1;
	max = get_max(array, size);
	while (max / position > 0)
	{
		radix_counting_sort(array, size, position, new_array);
		print_array(array, size);
		position *= 10;
	}
}
