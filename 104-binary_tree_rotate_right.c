#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	/* Check if the tree or its left child is NULL */
	if (tree == NULL || tree->left == NULL)
		return (tree);

	/* Define new root and temporary node */
	new_root = tree->left;
	temp = new_root->right;

	/* Perform the rotation */
	new_root->right = tree;
	tree->left = temp;

	/* Update parent pointers */
	if (temp != NULL)
		temp->parent = tree;

	new_root->parent = tree->parent;
	tree->parent = new_root;

	/* Update the parent's child pointer to new_root */
	if (new_root->parent != NULL)
	{
		if (new_root->parent->left == tree)
			new_root->parent->left = new_root;
		else
			new_root->parent->right = new_root;
	}

	return (new_root);
}
