#include "binary_trees.h"

/**
 * check_perfect_tree - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: Height of the tree starting at tree, or 0 if tree is NULL
 */

int check_perfect_tree(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree->left && tree->right)
	{
		left_height = 1 + check_perfect_tree(tree->left);
		right_height = 1 + check_perfect_tree(tree->right);
		if (right_height == left_height && right_height != 0 && left_height != 0)
			return (right_height);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		result = check_perfect_tree(tree);
		if (result != 0)
		{
			return (1);
		}
		return (0);
	}
}
