/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    if (this && this->str)
        return compare_c(this, str->str);
    return 84;
}

int compare_c(const string_t *this, const char *str)
{
    if (!this || !this->str || !str)
        return 84;
    return strcmp(this->str, str);
}