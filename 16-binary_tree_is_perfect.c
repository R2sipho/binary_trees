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
    if (tree == NULL || binary_tree_is_leaf(tree))
        return (0);

    size_t left = binary_tree_height(tree->left);
    size_t right = binary_tree_height(tree->right);

    return (1 + (left >= right ? left : right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    if (binary_tree_is_leaf(tree))
        return 1;

    binary_tree_t *l = tree->left;
    binary_tree_t *r = tree->right;

    if (l == NULL || r == NULL)
        return 0;

    return (binary_tree_height(l) == binary_tree_height(r) &&
            binary_tree_is_perfect(l) && binary_tree_is_perfect(r));
}

