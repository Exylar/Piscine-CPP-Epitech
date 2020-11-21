/*
** EPITECH PROJECT, 2019
** cpp_d02a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "generic_list.h"
#include <stddef.h>

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return 0;
    return (list->value);
}

void *list_get_elem_at_back(list_t list)
{
    if (list == NULL)
        return 0;
    for (int i = 0; list->next != NULL; i++)
        list = list->next;
    return list->value;
}

void *list_get_elem_at_position(list_t list,
unsigned int position)
{
    if (list == NULL || position < 0)
        return 0;
    if (position == 0)
        return (list_get_elem_at_front(list));
    for (int i = 0; i < position; i++) {
        if (list->next != NULL)
            list = list->next;
        else
            return 0;
    }
    return list->value;
}