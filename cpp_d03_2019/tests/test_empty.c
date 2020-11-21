/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, empty)
{
    string_t s;

    string_init(&s, "Hello World salut les amis");
    cr_assert_eq(empty(&s), 0);
    string_destroy(&s);
}

Test(str, empty_2)
{
    string_t s;

    string_init(&s, "\t");
    cr_assert_eq(empty(&s), 0);
    string_destroy(&s);
}

Test(str, empty_with_empty)
{
    string_t s;

    string_init(&s, "");
    cr_assert_eq(empty(&s), 1);
    string_destroy(&s);
}

Test(str, empty_with_NULL)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert_eq(empty(&s), 1);
    string_destroy(&s);
}

Test(str, empty_with_string_NULL)
{
    cr_assert_eq(empty(NULL), 1);
}
