/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "string.h"

void join_c(string_t *this, char delim, const char * const * tab)
{
    char separator[2];
    separator[0] = delim;
    separator[1] = '\0';

    if (!this || !tab)
        return;
    if (this->str) {
        free(this->str);
        this->str = NULL;
    }
    for (int i = 0; tab[i] != NULL; i++) {
        if (i == 0)
            assign_c(this, tab[i]);
        else
            append_c(this, tab[i]);
        if (tab[i + 1])
            append_c(this, separator);
    }
}

void join_s(string_t *this, char delim, const string_t * const * tab)
{
    char separator[2];
    separator[0] = delim;
    separator[1] = '\0';

    if (!this || !tab)
        return;
    if (this->str) {
        free(this->str);
        this->str = NULL;
    }
    for (int i = 0; tab[i] && tab[i]->str; i++) {
        if (i == 0)
            assign_s(this, tab[i]);
        else
            append_s(this, tab[i]);
        if (tab[i + 1])
            append_c(this, separator);
    }
}