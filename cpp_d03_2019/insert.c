/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "string.h"

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    if (this && this->str && str && str->str)
        insert_c(this, pos, str->str);
    return;
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *save_str_pos;

    if (!this || !this->str || !str)
        return;
    if (strlen(str) > strlen(this->str) || pos > strlen(this->str))
        return;
    save_str_pos = strdup(this->str + pos);
    this->str[pos] = '\0';
    append_c(this, str);
    append_c(this, save_str_pos);
    free(save_str_pos);
}
