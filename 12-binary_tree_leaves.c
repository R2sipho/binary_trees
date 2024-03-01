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
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the leaves in
 *
 * Description: A NULL pointer is not a leaf
 *
 * Return: number of leaves in a binary tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;
    
    if (binary_tree_is_leaf(tree))
        return 1;

    return binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
}

