/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, assign_s)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello World salut les amis");
    string_init(&s2, "Copy de s2");
    assign_s(&s, &s2);
    cr_assert_str_eq(s.str, "Copy de s2");
    string_destroy(&s);
}

Test(str, assign_c)
{
    string_t s;

    string_init(&s, "Hello World salut les amis");
    assign_c(&s, "Nouveau str");
    cr_assert_str_eq(s.str, "Nouveau str");
    string_destroy(&s);
}

Test(str, assign_c_Null)
{
    string_t s;

    string_init(&s, "Hello World salut les amis");
    assign_c(NULL, "Nouveau str");
    cr_assert_str_eq(s.str, "Hello World salut les amis");
    string_destroy(&s);
}