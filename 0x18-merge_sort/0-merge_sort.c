#include "sort.h"

/**
 * merge - merger two subarrys
 * @array: array
 * @right: right subarry
 * @left: left subarry
 * @size: size of array
 */
void merge(int *array, int *right, int *left, size_t size)
{
int li, ri, i = 0, j = 0, k = 0;

li = size / 2;
ri = size - li;

while (i < li && j < ri)
{
if (left[i] <= right[j])
{
array[k] = left[i];
i++;
}
else
{
array[k] = right[j];
j++;
}
k++;
}

while (i < li)
{
array[k] = left[i];
i++;
k++;
}

while (j < ri)
{
array[k] = right[j];
j++;
k++;
}
printf("Merging...\n");
printf("[left]: ");
print_array(left, li);
printf("[right]: ");
print_array(right, ri);
printf("[Done]: ");
print_array(array, size);
}

/**
 * merge_sort - Function that sorts an array of integers
 * in ascending order using the Merge Sort algorithm
 * @array: array
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
size_t m, i;
int right[300], left[300];

m = size / 2;

if (size < 2 || array == NULL)
return;

for (i = 0; i < m; i++)
left[i] = array[i];

for (i = m;  i < size; i++)
right[i - m] = array[i];

merge_sort(left, m);
merge_sort(right, size - m);
merge(array, right, left, size);
}
