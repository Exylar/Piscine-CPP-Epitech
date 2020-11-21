/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (!this)
        return -1;
    if (!this->str)
        return -1;
    return (pos > 0 && pos >= strlen(this->str)) ? -1 : this->str[pos];
}

void clear(string_t *this)
{
    if (this && this->str)
        memset(this->str, 0, strlen(this->str));
    return;
}

int size(const string_t *this)
{
    return (this && this->str) ? strlen(this->str) : (size_t)-1;
}

const char *c_str(const string_t *this)
{
    if (this && this->str)
        return this->str;
    return NULL;
}

int empty(const string_t *this)
{
    if (this && this->str && strlen(this->str) > 0)
        return (0);
    return (1);
}