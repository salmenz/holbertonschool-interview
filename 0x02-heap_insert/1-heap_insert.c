#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * heap_insert - inserts a value into a max binary heap
 * @root: pointer to root node
 * @value: node value integer
 * Return: pointer to the inserted node or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL;

	new = malloc(sizeof(heap_t));

	if (!new)
		return (NULL);

	

	return (new);
}