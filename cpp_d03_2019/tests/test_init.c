/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, init_null)
{
    string_init(NULL, "Hello World salut les amis");
}

Test(str, test1)
{
    string_t s;
    string_init(&s, "Hello World salut les amis");
    cr_assert_str_eq(s.str, "Hello World salut les amis");
    string_destroy(&s);
}