/*
** EPITECH PROJECT, 2019
** cpp_d02a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <stddef.h>
#include <stdio.h>
#include "double_list.h"

unsigned int double_list_get_size(double_list_t list)
{
    int i = 0;

    for (i; list != NULL; i++)
        list = list->next;
    return i;
}

bool double_list_is_empty(double_list_t list)
{
    if (list == NULL)
        return 1;
    return 0;
}

void double_list_dump(double_list_t list)
{
    for (int i = 0; list != NULL; i++) {
        printf("%f\n", list->value);
        list = list->next;
    }
}