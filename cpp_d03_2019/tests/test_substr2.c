/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, substr_offset_too_high)
{
    string_t *out;
    string_t s;

    string_init(&s, "Hello World salut les amis");
    out = substr(&s, -5, 9);
    cr_assert_eq(out, NULL);
    string_destroy(&s);
}


Test(str, substr_length_overflow)
{
    string_t *out;
    string_t s;

    string_init(&s, "Hello World salut les amis");
    out = substr(&s, 5, -50);
    cr_assert_eq(out, NULL);
    string_destroy(&s);
}

Test(str, substr_null)
{
    string_t *out;
    string_t s;

    string_init(&s, "Hello World salut les amis");
    out = substr(NULL, 6, 5);
    cr_assert_eq(out, NULL);
    string_destroy(&s);
}

Test(str, substr_overflow)
{
    string_t *out;
    string_t s;

    string_init(&s, "Hello World salut les amis");
    out = substr(&s, 60, 5);
    cr_assert_eq(out, NULL);
    string_destroy(&s);
}