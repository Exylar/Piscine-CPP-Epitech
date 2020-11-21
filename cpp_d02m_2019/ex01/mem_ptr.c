/*
** EPITECH PROJECT, 2019
** cpp_d02m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "mem_ptr.h"
#include <string.h>

void add_str(const char *str1, const char *str2, char **res)
{
    *res = strdup(strcat(strdup(str1), strdup(str2)));
}

void add_str_struct(str_op_t *str_op)
{
    str_op->res = strdup(strcat(strdup(str_op->str1), strdup(str_op->str2)));
}