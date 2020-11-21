/*
** EPITECH PROJECT, 2019
** cpp_d02a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "double_list.h"

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *new_node = malloc(sizeof(doublelist_node_t));
    new_node->value = elem;
    new_node->next = front_ptr[0];
    front_ptr[0] = new_node;
    return 1;
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *new_node = malloc(sizeof(doublelist_node_t));
    doublelist_node_t *save = front_ptr[0];

    if (front_ptr[0] != 0) {
        for (int i = 0; front_ptr[0]->next != 0; i++)
            front_ptr[0] = front_ptr[0]->next;
        new_node->value = elem;
        new_node->next = NULL;
        front_ptr[0]->next = new_node;
        front_ptr[0] = save;
        return 1;
    }
    new_node->value = elem;
    new_node->next = NULL;
    front_ptr[0] = new_node;
    return 1;
}

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
unsigned int position)
{
    doublelist_node_t *new_node = malloc(sizeof(doublelist_node_t));
    doublelist_node_t *save = front_ptr[0];
    doublelist_node_t *save_next;

    if (front_ptr[0] == 0 && position > 0)
        return 0;
    if (double_list_get_size(*front_ptr) <= position)
        return 0;
    if (position == 0)
        return (double_list_add_elem_at_front(front_ptr, elem));
    for (int i = 0; i < position - 1; i++) {
        if (front_ptr[0]->next != NULL)
            front_ptr[0] = front_ptr[0]->next;
        else
            return 0;
    }
    save_next = front_ptr[0]->next;
    front_ptr[0]->next = new_node;
    new_node->value = elem;
    new_node->next = save_next;
    front_ptr[0] = save;
}