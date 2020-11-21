/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, c_str)
{
    string_t s;

    string_init(&s, "Hello World salut les amis");
    cr_assert_str_eq(c_str(&s), "Hello World salut les amis");
    string_destroy(&s);
}

Test(str, c_str_null)
{
    string_t s;

    string_init(&s, "Hello World salut les amis");
    cr_assert_eq(c_str(NULL), NULL);
    string_destroy(&s);
}
