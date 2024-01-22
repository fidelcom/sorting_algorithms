#include "sort.h"
/**
 * print_left_right - prints left, right, and merged halves
 * @arr: original or tmp array
 * @side: left, right, or merged half
 * @start: starting index
 * @end: ending index
 */
void print_left_right(int *arr, char *side, size_t start, size_t end)
{
	size_t i;

	printf("[%s]: ", side);
	for (i = start; i < end; i++)
	{
		if (i != (end - 1))
			printf("%d, ", arr[i]);
		else
			printf("%d\n", arr[i]);
	}

}
/**
 * recursive_merge - recursively splits and merges halves
 * @array: original array
 * @sortArr: tmp array to hold sorted elements
 * @left: starting index
 * @right: ending index
 */
void recursive_merge(int *array, int *sortArr, size_t left, size_t right)
{
	size_t i, left_half, right_half;
	size_t mid = (left + right) / 2;

	if (right - left <= 1)
		return;

	recursive_merge(array, sortArr, left, mid);
	recursive_merge(array, sortArr, mid, right);
	printf("Merging...\n");
	print_left_right(array, "left", left, mid);
	print_left_right(array, "right", mid, right);
	left_half = left;
	right_half = mid;
	for (i = left; i < right; i++)
	{
		if ((left_half < mid) &&
		    ((right_half == right) || (array[left_half] < array[right_half])))
		{
			sortArr[i] = array[left_half];
			left_half++;
		}
		else
		{
			sortArr[i] = array[right_half];
			right_half++;
		}
	}
	print_left_right(sortArr, "Done", left, right);
	for (i = left; i < right; i++)
		array[i] = sortArr[i];
}
/**
 * merge_sort - sorts mergly
 * @array: array sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *sort_arr;

	if (!(array) || size < 2)
		return;
	sort_arr = malloc(sizeof(int) * size);
	if (!(sort_arr))
		return;
	recursive_merge(array, sort_arr, 0, size);
	free(sort_arr);
}
