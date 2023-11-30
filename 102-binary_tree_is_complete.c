#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: (1) if the tree is complete, (0) otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int flag = 0;  /* Flag to indicate if we've encountered non-full node */
	binary_tree_t **queue, *current;
	size_t front = 0, rear = 0;

	if (tree == NULL)
		return (0);

	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		current = queue[front++];

		if (current == NULL)
			flag = 1; /* If we encounter a NULL node, set the flag */

		else if (flag)
		{
			free(queue);
			return (0);
		}
		else
		{
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}

	/* If we've reached here, the tree is complete */
	free(queue);
	return (1);
}
