/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, find_s)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello World salut les amis");
    string_init(&s2, "les");
    cr_assert_eq(find_s(&s, &s2, 0), 18);
    string_destroy(&s);
    string_destroy(&s2);
}

Test(str, find_s_null)
{
    string_t s;

    string_init(&s, "Hello World salut les amis");
    cr_assert_eq(find_s(&s, NULL, 0), -1);
    string_destroy(&s);
}

Test(str, find_c_null)
{
    string_t s;

    string_init(&s, "Hello World salut les amis");
    cr_assert_eq(find_c(&s, NULL, 0), -1);
    string_destroy(&s);
}

Test(str, find_c_size_overflow)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello World salut les amis");
    string_init(&s2, "les");
    cr_assert_eq(find_s(&s, &s2, -1), -1);
    string_destroy(&s);
    string_destroy(&s2);
}

Test(str, find_c_not_find)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello World salut les amis");
    string_init(&s2, "test");
    cr_assert_eq(find_s(&s, &s2, 0), -1);
    string_destroy(&s);
    string_destroy(&s2);
}