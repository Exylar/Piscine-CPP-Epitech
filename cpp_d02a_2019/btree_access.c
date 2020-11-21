/*
** EPITECH PROJECT, 2019
** cpp_d02a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <stdlib.h>
#include "double_btree.h"

double double_btree_get_max_value(double_btree_t tree)
{
    double node_l = -__DBL_MAX__;
    double node_r = -__DBL_MAX__;
    double res = -__DBL_MAX__;

    if (tree == 0)
        return 0;
    node_l = double_btree_get_max_value(tree->left);
    node_r = double_btree_get_max_value(tree->right);
    res = (node_l > node_r) ? node_l : node_r;
    return (tree->value > res) ? tree->value : res;
}

double double_btree_get_min_value(double_btree_t tree)
{
    double node_l = __DBL_MAX__;
    double node_r = __DBL_MAX__;
    double res = __DBL_MAX__;

    if (tree == 0)
        return 0;
    if (tree->left != 0)
        node_l = double_btree_get_min_value(tree->left);
    if (tree->right != 0)
        node_r = double_btree_get_min_value(tree->right);
    res = (node_l < node_r) ? node_l : node_r;
    return (tree->value < res) ? tree->value : res;
}