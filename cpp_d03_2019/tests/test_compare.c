/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, compare_s)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello World salut les amis");
    string_init(&s2, "Hello World salut les amis");
    cr_assert_eq(compare_s(&s, &s2), 0);
    string_destroy(&s);
    string_destroy(&s2);
}

Test(str, compare_s_null)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello World salut les amis");
    string_init(&s2, "Hello World salut les amis");
    cr_assert_eq(compare_s(NULL, &s2), 84);
    string_destroy(&s);
    string_destroy(&s2);
}

Test(str, compare_c_null)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello World salut les amis");
    string_init(&s2, "Hello World salut les amis");
    cr_assert_eq(compare_c(NULL, "Hello"), 84);
    string_destroy(&s);
    string_destroy(&s2);
}