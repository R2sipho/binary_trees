#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @node: pointer to the node to measure the depth of
 *
 * Return: depth of a node in a binary tree. If node is NULL, return 0
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL)
        return 0;

    return 1 + binary_tree_depth(node->parent);
}

