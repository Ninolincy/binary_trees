#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: First node.
 * @second: Second node.
 *
 * Return: Pointer to the ancestor node, or NULL if there is no ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t first_dpth, second_dpth;

	if (!first || !second)
		return (NULL);

	first_dpth = binary_tree_depth(first);
	second_dpth = binary_tree_depth(second);

	/** Adjust nodes to the same depth */
	while (first_dpth > second_dpth)
	{
		first = first->parent;
		first_dpth--;
	}
	while (second_dpth > first_dpth)
	{
		second = second->parent;
		second_dpth--;
	}

	/** Traverse upwards until a common ancestor is found */
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	/** NULL if no common ancestor found */
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - Depth of tree node
 * @tree: node.
 *
 * Return: Node depth, or 0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
