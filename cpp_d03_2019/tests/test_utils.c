/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, clear_size_0)
{
    string_t s;

    string_init(&s, "Hello World salut les amis");
    clear(&s);
    cr_assert_eq(size(&s), 0);
    string_destroy(&s);
}

Test(str, size)
{
    string_t s;

    string_init(&s, "Hello World salut les amis");
    cr_assert_eq(size(&s), 26);
    string_destroy(&s);
}