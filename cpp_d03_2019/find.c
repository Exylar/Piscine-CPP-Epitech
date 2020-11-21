/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if (this && this->str && str && str->str)
        return find_c(this, str->str, pos);
    return -1;
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *find_str_pos;

    if (!this || !this->str || !str)
        return -1;
    if (strlen(str) > strlen(this->str) || pos > strlen(this->str))
        return -1;
    find_str_pos = strstr(this->str + pos, str);
    if (find_str_pos == NULL)
        return -1;
    return find_str_pos - this->str;
}