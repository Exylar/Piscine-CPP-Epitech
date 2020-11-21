/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "string.h"

void last_init(string_t *this)
{
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_s = &insert_s;
    this->insert_c = &insert_c;
    this->to_int = &to_int;
    this->split_s = &split_s;
    this->split_c = &split_c;
    this->print = &print;
    this->join_s = &join_s;
    this->join_c = &join_c;
    this->substr = &substr;
}

void string_init(string_t *this, const char *str)
{
    if (!this)
        return;
    this->str = (str) ? strdup(str) : NULL;
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    last_init(this);
}

void string_destroy(string_t *this)
{
    if (this && this->str) {
        free(this->str);
        this->str = NULL;
    }
}