/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = 0;

    if (!this || !s || !this->str)
        return 0;
    for (i = 0; i + pos < strlen(this->str) && i < n; i++)
        s[i] = this->str[i + pos];
    if (strlen(s) < n)
        s[i++] = '\0';
    return i;
}