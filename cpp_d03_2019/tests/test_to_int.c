/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, to_int)
{
    string_t s;

    string_init(&s, "26");
    cr_assert_eq(to_int(&s), 26);
    string_destroy(&s);
}

Test(str, to_int_with_text)
{
    string_t s;

    string_init(&s, "26ddsdsdsds");
    cr_assert_eq(to_int(&s), 26);
    string_destroy(&s);
}

Test(str, to_int_with_text_before)
{
    string_t s;

    string_init(&s, "salut27bonsoir28");
    cr_assert_eq(to_int(&s), 0);
    string_destroy(&s);
}

Test(str, to_int_NULL)
{
    string_t s;

    string_init(&s, "salut27bonsoir28");
    cr_assert_eq(to_int(NULL), 0);
    string_destroy(&s);
}