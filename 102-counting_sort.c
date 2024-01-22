#include "sort.h"
/**
 * counting_sort - counting sort algo
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int j, k, num, dp;
	int *cnts;

	if (array == NULL || size < 2)
		return;
	k = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	cnts = malloc(sizeof(int) * (k + 1));
	if (cnts == NULL)
		return;
	for (j = 0; j < (k + 1); j++)
		cnts[j] = 0;
	for (i = 0; i < size; i++)
	{
		num = array[i];
		cnts[num] += 1;
	}
	for (j = 0; j < k; j++)
	{
		cnts[j + 1] += cnts[j];
	}
	print_array(cnts, k + 1);
	for (i = 0, j = 0; j < k; j++)
	{
		if ((j == 0) && cnts[j] != 0)
		{
			for ((dp = cnts[j]); dp > 0; dp--)
				array[i++] = j;
		}
		if (cnts[j + 1] > cnts[j])
		{
			for ((dp = cnts[j + 1] - cnts[j]); dp > 0; dp--)
				array[i++] = (j + 1);
		}
	}

	free(cnts);
}
