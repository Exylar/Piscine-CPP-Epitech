/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "string.h"

string_t *substr(const string_t *this, int offset, int length)
{
    char *str;
    string_t *new_str = malloc(sizeof(string_t));
    int i = 0;

    if (!this || !this->str || offset >= size(this) || length >= size(this))
        return NULL;
    if (offset < 0) {
        offset = size(this) + offset;
        if ((size(this) - offset) < length || offset < 0)
            return NULL;
    }
    if (offset > 0 && length < 0 && offset < abs(length))
        return NULL;
    str = malloc(sizeof(char) * abs(length) + 1);
    for (i = 0; i < size(this) && abs(length) > i; i++)
        str[i] = this->str[offset + ((length >= 0) ? i : (i - 1) + length + 1)];
    str[i] = '\0';
    string_init(&new_str[0], str);
    free(str);
    return new_str;
}