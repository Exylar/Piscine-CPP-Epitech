/*
** EPITECH PROJECT, 2019
** cpp_d02a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <stdlib.h>
#include "double_btree.h"

bool double_btree_create_node(double_btree_t *root_ptr, double value)
{
    double_btree_t new_node = malloc(sizeof(double_btree_t));
    root_ptr[0] = new_node;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return 1;
}

bool double_btree_delete(double_btree_t *root_ptr)
{
    if (root_ptr[0] == 0)
        return 0;
    if (root_ptr[0]->right != NULL)
        double_btree_delete(&root_ptr[0]->right);
    if (root_ptr[0]->left != NULL)
        double_btree_delete(&root_ptr[0]->left);
    free(root_ptr[0]);
    return 1;
}