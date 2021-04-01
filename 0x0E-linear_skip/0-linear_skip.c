#include "search.h"
/**
 * find - searches in the linked list to find the value
 * @prev: the previous pointer
 * @actu: the actuual pointer
 * @value: the value to search
 * Return: node
 */
skiplist_t *find(skiplist_t *prev, skiplist_t *actu, int value)
{
while (prev && prev->index <= actu->index)
{
printf("Value checked at index [%lu] = [%i]\n", prev->index, prev->n);
if (prev->n == value)
{
return (prev);
}
prev = prev->next;
}
return (NULL);
}

/**
 * linear_skip - function that searches for a value
 * @list: list of search
 * @value: value
 * Return: the pointer or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *actu, *prev;
size_t actut, prevv;
if (!list)
return (NULL);
actu = list;
while (actu->express != NULL)
{
prev = actu;
actu = actu->express;
actut = actu->index;
prevv = prev->index;
printf("Value checked at index [%lu] = [%i]\n", actut, actu->n);
if (prev->n > value && prev->index == 0)
return (NULL);
if (actu->n >= value)
{
break;
}
}
if (!actu->express && actu->n < value)
{
prev = actu;
prevv = prev->index;
while (actu->next)
actu = actu->next;
actut = actu->index;
}
printf("Value found between indexes [%lu] and [%lu]\n", prevv, actut);
return (find(prev, actu, value));
}
