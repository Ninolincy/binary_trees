#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor, 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left = 0;
	int height_right = 0;

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
	if (!tree)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ?
		 left_height + 1 : right_height + 1));
}
