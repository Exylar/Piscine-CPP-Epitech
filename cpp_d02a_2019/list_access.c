/*
** EPITECH PROJECT, 2019
** cpp_d02a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "generic_list.h"
#include <stdio.h>

node_t *list_get_first_node_with_value(list_t list, void *value,
value_comparator_t val_comp)
{
    while (list != NULL) {
        if ((val_comp)(list->value, value) == 0)
            return list;
        list = list->next;
    }
    return NULL;
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    if (list != 0) {
        val_disp(list->value);
        if (list->next != NULL)
            list_dump(list->next, val_disp);
    }
}