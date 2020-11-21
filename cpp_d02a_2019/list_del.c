/*
** EPITECH PROJECT, 2019
** cpp_d02a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "generic_list.h"
#include <stdlib.h>
#include <stddef.h>

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t node = front_ptr[0];

    if (front_ptr[0] == 0)
        return 0;
    front_ptr[0] = front_ptr[0]->next;
    free(node);
    return 1;
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t save = front_ptr[0];

    if (front_ptr[0] == 0)
        return 1;
    if (front_ptr[0]->next == 0) {
        front_ptr[0] = NULL;
        return 0;
    } else if (front_ptr[0]->next->next == 0) {
        front_ptr[0]->next = NULL;
        return 0;
    }
    for (int i = 0; front_ptr[0]->next->next != NULL; i++)
        front_ptr[0] = front_ptr[0]->next;
    free(front_ptr[0]->next);
    front_ptr[0]->next = NULL;
    front_ptr[0] = save;
    return 0;
}

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t save = front_ptr[0];
    list_t save_next;

    if (front_ptr[0] == 0 || list_get_size(*front_ptr) <= position)
        return 0;
    if (position == 0)
        return (list_del_elem_at_front(front_ptr));
    for (int i = 0; i < position - 1; i++) {
        if (front_ptr[0]->next != NULL)
            front_ptr[0] = front_ptr[0]->next;
        else
            return 0;
    }
    save_next = front_ptr[0]->next->next;
    free(front_ptr[0]->next);
    front_ptr[0]->next = save_next;
    front_ptr[0] = save;
    return 1;
}

void list_clear(list_t *front_ptr)
{
    if (front_ptr[0] != 0)
        list_clear(&front_ptr[0]->next);
    front_ptr[0] = NULL;
}