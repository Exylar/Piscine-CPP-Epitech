/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (this && str->str)
        assign_c(this, str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (!this)
        return;
    if (this->str)
        free(this->str);
    this->str = strdup(s);
}
