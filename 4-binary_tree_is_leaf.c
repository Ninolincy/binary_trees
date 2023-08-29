#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * @node: Node to check.
 *
 * Return: 1 if node is a leaf, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/** Check if the node is NULL or has children */
	return (node && !node->left && !node->right);
}
