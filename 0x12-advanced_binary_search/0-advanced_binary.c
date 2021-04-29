#include "search_algos.h"

/**
 * advanced_binary - function search the value into the array
 * @array: pointer to array
 * @size: size
 * @value: value
 * Return: the index or -1
 */

int advanced_binary(int *array, size_t size, int value)
{
size_t i, h, index_el = 0;
int tmp;

if (array == NULL)
return (-1);

printf("Searching in array: ");
for (i = 0; i < size; i++)
{
if (i == size - 1)
printf("%d\n", array[i]);
else
printf("%d, ", array[i]);
}

if (size == 1 && array[0] != value)
return (-1);

h = (size - 1) / 2;

if (array[h] == value)
{
if (array[h - 1] < value)
return (h);
}

if (array[h] < value)
{
index_el += h + 1;
array += h + 1;
if (size % 2 != 0)
h--;
}

h++;
tmp = advanced_binary(array, h, value);
if (tmp != -1)
return (tmp + index_el);

return (-1);
}
