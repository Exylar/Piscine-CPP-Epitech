/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, substr)
{
    string_t *out;
    string_t s;

    string_init(&s, "Hello World salut les amis");
    out = substr(&s, 6, 5);
    cr_assert_str_eq(out[0].str, "World");
    string_destroy(&s);
}

Test(str, substr_offset_neg)
{
    string_t *out;
    string_t s;

    string_init(&s, "Hello World salut les amis");
    out = substr(&s, -5, 5);
    cr_assert_str_eq(out[0].str, " amis");
    string_destroy(&s);
}

Test(str, substr_length_neg)
{
    string_t *out;
    string_t s;

    string_init(&s, "Hello World salut les amis");
    out = substr(&s, 5, -5);
    cr_assert_str_eq(out[0].str, "Hello");
    string_destroy(&s);
}