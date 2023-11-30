#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *ancestor = first;
	const binary_tree_t *temp;

	if (first == NULL || second == NULL)
		return (NULL);

	while (ancestor != NULL)
	{
		temp = second;

		while (temp != NULL)
		{
			if (ancestor == temp)
				return ((binary_tree_t *)ancestor);

			temp = temp->parent;
		}

		ancestor = ancestor->parent;
	}

	return (NULL);
}
