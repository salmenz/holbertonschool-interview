#include "binary_trees.h"

/**
 * less - check if a less contains only values less than n
 * @tree: tree
 * @n: value to check
 * @flag: 1 if left or 0 if right
 * Return: 1 if true, otherwise 0
 */

int less(const binary_tree_t *tree, int n, int flag)
{
	int r_left = 1, r_right = 1;

	if (tree->left)
		r_left = less(tree->left, n, flag);
	if (tree->right)
		r_right = less(tree->right, n, flag);
	if (flag && tree->n >= n)
		return (0);
	else if (!flag && tree->n <= n)
		return (0);
	return (r_left * r_right);
}
/**
 * BS_tree - check if a tree is a Binary search tree
 * @tree: tree
 * Return: 1 if true, otherwise 0
 */
int BS_tree(const binary_tree_t *tree)
{
	int r_left = 1, r_right = 1;

	if (!tree)
		return (0);
	if (tree->left)
	{
		if (!less(tree->left, tree->n, 1))
			return (0);
		r_left = BS_tree(tree->left);
	}
	else
		return (1);
	if (tree->right)
	{
		if (!less(tree->right, tree->n, 0))
			return (0);
		r_right = BS_tree(tree->right);
	}
	else
		return (1);
	return (r_left * r_right);
}

/**
 * height - help to calculate the height of the tree
 * @tree: tree
 * Return: the height
 */

size_t height(const binary_tree_t *tree)
{
	size_t c_left = 0, c_right = 0;

	if (tree->left)
		c_left = height(tree->left);
	if (tree->right)
		c_right = height(tree->right);
	return ((c_left > c_right) ? c_left + 1 : c_right + 1);
}

/**
 * balance_binary - calculate the height of the tree
 * @tree: tree
 * Return: the height of the tree, 0 if tree is null
 */
int balance_binary(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree)
	{
		if (tree->left)
			left = height(tree->left);
		if (tree->right)
			right = height(tree->right);
		return (left - right);
	}
	else
		return (0);
}

/**
 * binary_tree_is_avl - check if a binary tree is a valid AVLTree
 * @tree: tree
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int r_left = 1, r_right = 1;

	if (!tree)
		return (0);

	if ((balance_binary(tree) != 1 && balance_binary(tree) != 0 &&
	balance_binary(tree) != -1) || !BS_tree(tree))
		return (0);
	if (tree->left)
		r_left = binary_tree_is_avl(tree->left);
	if (tree->right)
		r_right = binary_tree_is_avl(tree->right);

	return (r_left * r_right);
}
