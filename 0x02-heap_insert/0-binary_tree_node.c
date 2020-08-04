#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - add node in binary tree
 * @parent: the parent of the node
 * @value: the value of the node
 * Return: tree
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new;
new = malloc(sizeof(binary_tree_t));
if (new == NULL)
    return (NULL);
new->left = NULL;
new->right = NULL;
if (parent == NULL)
{
    new->parent = NULL;
    new->n = value;
    return (new);
}
new->parent = parent;
new->n = value;
return (new);
}