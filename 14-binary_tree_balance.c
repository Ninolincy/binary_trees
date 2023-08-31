#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor, 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left = -1;
	int height_right = -1;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = (int)binary_tree_height(tree->left);
	if (tree->right)
		height_right = (int)binary_tree_height(tree->right);

	return (height_left - height_right);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Tree to measure the height of.
 *
 * Return: Height of the tree, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_left > height_right ? height_left : height_right);
}
