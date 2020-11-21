/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, at)
{
    string_t s;
    string_init(&s, "Hello World salut les amis");
    cr_assert_eq(at(&s, 6), 'W');
    string_destroy(&s);
}

Test(str, at_null)
{
    string_t s;
    string_init(&s, "Hello World salut les amis");
    cr_assert_eq(at(NULL, 6), -1);
    string_destroy(&s);
}

Test(str, at_str_null)
{
    string_t s;
    string_init(&s, NULL);
    cr_assert_eq(at(&s, 6), -1);
    string_destroy(&s);
}