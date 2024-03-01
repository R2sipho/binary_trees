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
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t left = binary_tree_height(tree->left);
    size_t right = binary_tree_height(tree->right);

    return (1 + (left >= right ? left : right));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor of
 *
 * Description: If tree is NULL, return 0
 *
 * Return: balance factor of a binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return binary_tree_height(tree->left) - binary_tree_height(tree->right);
}

