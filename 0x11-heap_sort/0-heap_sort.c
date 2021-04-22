
#include <stdio.h>
#include "sort.h"
#include <stdlib.h>
/**
 * sort - sort array
 * @array: array
 * @size: array size
 * @i: counter
 * @cs: complete size
 */
void sort(int *array, size_t size, int i, size_t cs)
{
int p, left, right, swipe;

p = i;
left = 2 * i + 1;
right = 2 * i + 2;
if (left < (int)size && array[left] > array[p])
p = left;
if (right < (int)size && array[right] > array[p])
p = right;
if (p != i)
{
swipe = array[i];
array[i] = array[p];
array[p] = swipe;
print_array(array, (int)cs);
sort(array, (int)size, p, (int)cs);
}
}
/**
 * heap_sort - sort array
 * @array: array to be sorted
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
int i, swipe;
if (size == 0)
return;
for (i = (int)size / 2 - 1; i >= 0; i--)
sort(array, (int)size, i, size);
for (i = (int)size - 1; i > 0; i--)
{
swipe = array[0];
array[0] = array[i];
array[i] = swipe;
print_array(array, (int)size);
sort(array, i, 0, size);
}
}
