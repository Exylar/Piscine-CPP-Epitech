/*
** EPITECH PROJECT, 2019
** cpp_d02a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <stddef.h>
#include "double_list.h"

double double_list_get_elem_at_front(double_list_t list)
{
    if (list == NULL)
        return 0;
    return (list->value);
}

double double_list_get_elem_at_back(double_list_t list)
{
    if (list == NULL)
        return 0;
    for (int i = 0; list->next != NULL; i++)
        list = list->next;
    return list->value;
}

double double_list_get_elem_at_position(double_list_t list,
unsigned int position)
{
    if (list == NULL || position < 0)
        return 0;
    if (position == 0)
        return (double_list_get_elem_at_front(list));
    for (int i = 0; i < position; i++) {
        if (list->next != NULL)
            list = list->next;
        else
            return 0;
    }
    return list->value;
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
double value)
{
    if (list == NULL)
        return NULL;
    for (int i = 0; list != NULL; i++) {
        if (list->value == value)
            return list;
        list = list->next;
    }
    return NULL;
}
