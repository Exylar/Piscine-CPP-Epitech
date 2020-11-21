/*
** EPITECH PROJECT, 2019
** cpp_d02a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "generic_list.h"
#include <stdlib.h>
#include <stddef.h>

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t new_node = malloc(sizeof(list_t));
    new_node->value = elem;
    new_node->next = front_ptr[0];
    front_ptr[0] = new_node;
    return 1;
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t new_node = malloc(sizeof(list_t));
    list_t save = front_ptr[0];

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

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
unsigned int position)
{
    list_t new_node = malloc(sizeof(list_t));
    list_t save;
    list_t save_next;

    if (front_ptr == 0 && position > 0 || list_get_size(*front_ptr) < position)
        return 0;
    if (position == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    save = front_ptr[0];
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
    return 1;
}