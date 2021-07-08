#include "sort.h"

/**
 * power - calculate power of 10
 * @power: power
 * Return: 10**power
 */

int power(int power)
{
	int i, result = 1;

	for (i = 0; i < power; i++)
		result *= 10;
	return (result);
}

/**
 * sort - sort a matrix
 * @array: array
 * @tmp: matrix
 * @size: size
 * @l: digit to apply sortting
 * Return: 0 if mostright and 1 otherwise
 */


int sort(int *array, int **tmp, size_t size, int l)
{
	int n, k = 0, max = 0;
	int idx[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i, j = 0;

	for (i = 0; i < size; i++)
	{
		n = (array[i] % power(l)) / power(l - 1);
		tmp[n][idx[n]++] = array[i];
		if (array[i] > max)
			max = array[i];
	}

	for (i = 0; i < 10; i++)
	{
		while (idx[i] != 0 && k < idx[i])
		{
			array[j + k] = tmp[i][k];
			k++;
		}
		j += k;
		k = 0;
	}
	print_array(array, size);
	if (max / power(l) == 0)
		return (0);
	return (1);
}


/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: array
 * @size: size
 */

void radix_sort(int *array, size_t size)
{
	int **tmp, aux = 1, l = 1;
	size_t i;

	if (!array || size < 2)
		return;
	tmp = malloc(sizeof(int *) * 10);
	for (i = 0; i < 10; i++)
		tmp[i] = malloc(sizeof(int) * size);
	while (aux)
		aux = sort(array, tmp, size, l++);
	for (i = 0; i < 10; i++)
		free(tmp[i]);
	free(tmp);
}
