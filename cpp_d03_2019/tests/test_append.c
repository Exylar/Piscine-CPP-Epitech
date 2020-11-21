/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, append_s)
{
    string_t s;
    string_init(&s, "Hello World salut les amis");
    string_t s2;
    string_init(&s2, " ajout de s2");
    append_s(&s, &s2);
    cr_assert_str_eq(s.str, "Hello World salut les amis ajout de s2");
    string_destroy(&s);
    string_destroy(&s2);
}

Test(str, append_c_Null)
{
    string_t s;
    string_init(&s, "Hello World salut les amis");
    append_c(NULL, "Nouveau str");
    cr_assert_str_eq(s.str, "Hello World salut les amis");
    string_destroy(&s);
}