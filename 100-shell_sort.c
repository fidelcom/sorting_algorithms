#include "sort.h"
/**
 * shell_sort - sorts shelly like
 * @array: array to take in
 * @size: size of array
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t space = 1, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (space < size / 3)
		space = (space * 3) + 1;

	while (space)
	{
		for (i = space; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= space && array[j - space] > tmp; j -= space)
			{
				array[j] = array[j - space];
			}
			array[j] = tmp;
		}
		print_array(array, size);
		space /= 3;
	}
}
