#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses binary tree
 *                           with a level-order traversal.
 * @tree: Tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxlevel;

	if (!tree || !func)
		return;

	maxlevel = binary_tree_height(tree) + 1;

	for (level = 1; level <= maxlevel; level++)
		level_tr_helper(tree, func, level);
}

/**
 * level_tr_helper - level-order traversal.
 * @tree: Tree to traverse.
 * @func: function to call nodes.
 * @level: The level of the tree to call func on.
 */
void level_tr_helper(const binary_tree_t *tree, void (*func)(int),
					 size_t level)
{
	if (level == 1)
	{
		func(tree->n);
		return;
	}

	if (tree->left)
		level_tr_helper(tree->left, func, level - 1);

	if (tree->right)
		level_tr_helper(tree->right, func, level - 1);
}
