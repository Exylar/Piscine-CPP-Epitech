/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "string.h"

int to_int(const string_t *this)
{
    if (this && this->str)
        return atoi(this->str);
    return 0;
}

void print(const string_t *this)
{
    if (this && this->str)
        printf("%s", this->str);
    return;
}