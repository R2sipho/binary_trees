#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_tree_recursive - Recursively populates the tree representation.
 */
static int print_tree_recursive(const binary_tree_t *tree, int offset,
                                int depth, char **s)
{
    if (!tree)
        return 0;

    char buffer[12];
    int width = sprintf(buffer, "(%03d)", tree->n);
    int left = print_tree_recursive(tree->left, offset, depth + 1, s);
    int right = print_tree_recursive(tree->right, offset + left + width, depth + 1, s);

    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = buffer[i];

    if (depth && tree->parent)
    {
        char connector = tree->parent->left == tree ? '.' : '-';
        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width / 2 + i] = connector;
    }

    return left + width + right;
}

/**
 * tree_height - Returns the height of the binary tree.
 */
static size_t tree_height(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    size_t height_left = tree_height(tree->left);
    size_t height_right = tree_height(tree->right);

    return 1 + (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_print - Prints a binary tree.
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (!tree)
        return;

    size_t height = tree_height(tree);
    char **tree_representation = malloc(sizeof(*tree_representation) * (height + 1));

    if (!tree_representation)
        return;

    for (size_t i = 0; i < height + 1; i++)
    {
        tree_representation[i] = malloc(sizeof(**tree_representation) * 255);

        if (!tree_representation[i])
        {
            for (size_t j = 0; j < i; j++)
                free(tree_representation[j]);

            free(tree_representation);
            return;
        }

        memset(tree_representation[i], ' ', 254);
    }

    print_tree_recursive(tree, 0, 0, tree_representation);

    for (size_t i = 0; i < height + 1; i++)
    {
        for (int j = 254; j > 1; --j)
        {
            if (tree_representation[i][j] != ' ')
                break;

            tree_representation[i][j] = '\0';
        }

        printf("%s\n", tree_representation[i]);
        free(tree_representation[i]);
    }

    free(tree_representation);
}

