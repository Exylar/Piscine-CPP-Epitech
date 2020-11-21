/*
** EPITECH PROJECT, 2019
** cpp_d02a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "generic_list.h"
#include <stddef.h>

unsigned int list_get_size(list_t list)
{
    int i = 0;

    for (i; list != NULL; i++)
        list = list->next;
    return i;
}

bool list_is_empty(list_t list)
{
    if (list == NULL)
        return 1;
    return 0;
}