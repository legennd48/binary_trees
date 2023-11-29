#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary tree node
 * @parent: Parent node
 * @Value: Value of the node
 * Return: The new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int Value)
{
	binary_tree_t *newNode;

	newNode = malloc(sizeof(binary_tree_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = Value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}
