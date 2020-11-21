/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, insert_s)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello World salut les amis");
    string_init(&s2, "test ");
    insert_s(&s, 6, &s2);
    cr_assert_str_eq(s.str, "Hello test World salut les amis");
    string_destroy(&s);
    string_destroy(&s2);
}

Test(str, insert_c)
{
    string_t s;

    string_init(&s, "Hello World salut les amis");
    insert_c(&s, 6, "test ");
    cr_assert_str_eq(s.str, "Hello test World salut les amis");
    string_destroy(&s);
}

Test(str, insert_c_NULL)
{
    string_t s;

    string_init(&s, "Hello World salut les amis");
    insert_c(&s, 6, NULL);
    cr_assert_str_eq(s.str, "Hello World salut les amis");
    string_destroy(&s);
}

Test(str, insert_c_p_NULL)
{
    string_t s;

    string_init(&s, "Hello World salut les amis");
    insert_c(NULL, 6, "test");
    cr_assert_str_eq(s.str, "Hello World salut les amis");
    string_destroy(&s);
}

Test(str, insert_c_value_error)
{
    string_t s;

    string_init(&s, "Hello World salut les amis");
    insert_c(&s, 60, "test");
    cr_assert_str_eq(s.str, "Hello World salut les amis");
    string_destroy(&s);
}