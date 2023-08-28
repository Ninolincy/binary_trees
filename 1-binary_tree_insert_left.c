#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 * @parent: pointer to the node to insert left child in
 * @value: value to store in the new node
 * Description: If parent  has a left child, the new node takes its place
 * and the old is set as left child to the new node.
 * Return: pointer to the created node, NULL on failure or parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	{
	if (new_node == NULL)
		return (NULL);
	}

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = parent->left;
	new_node->right = NULL;

	if (parent->left != NULL)
		parent->left->parent = new_node;
	parent->left = new_node;

	return (new_node);
}

