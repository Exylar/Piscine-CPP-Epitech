/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    if (this && ap->str)
        append_c(this, ap->str);
}

void append_c(string_t *this, const char *ap)
{
    if (!this)
        return;
    this->str = realloc(this->str, strlen(this->str) + strlen(ap) + 1);
    this->str = strcat(this->str, ap);
}
