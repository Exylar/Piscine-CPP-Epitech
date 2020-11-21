/*
** EPITECH PROJECT, 2019
** cpp_d02a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "double_btree.h"
#include <stdio.h>

bool double_btree_is_empty(double_btree_t tree)
{
    if (tree == 0)
        return 1;
    return 0;
}

unsigned int double_btree_get_size(double_btree_t tree)
{
    if (tree == 0)
        return 0;
    return 1 + double_btree_get_size(tree->left) +
        double_btree_get_size(tree->right);
}

unsigned int double_btree_get_depth(double_btree_t tree)
{
    int node_l = 0;
    int node_r = 0;

    if (tree == NULL)
        return 0;
    node_l = double_btree_get_depth(tree->left);
    node_r = double_btree_get_depth(tree->right);
    return 1 + ((node_l > node_r) ? node_l : node_r);
}