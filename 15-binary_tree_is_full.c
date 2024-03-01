#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    return (node && !node->left && !node->right);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if full, otherwise 0. If tree is NULL, return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    if (binary_tree_is_leaf(tree))
        return 1;

    int left = binary_tree_is_full(tree->left);
    int right = binary_tree_is_full(tree->right);

    return (left && right);
}

