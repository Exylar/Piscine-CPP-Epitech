/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, split_c)
{
    char **array;
    string_t s;

    string_init(&s, "Hello World salut les amis");
    array = split_c(&s, ' ');
    cr_assert_str_eq(array[0], "Hello");
    cr_assert_str_eq(array[1], "World");
    cr_assert_str_eq(array[2], "salut");
    cr_assert_str_eq(array[3], "les");
    cr_assert_str_eq(array[4], "amis");
    cr_assert_eq(array[5], NULL);
    string_destroy(&s);
}

Test(str, split_s)
{
    string_t **array;
    string_t s;

    string_init(&s, "Hello World salut les amis");
    array = split_s(&s, ' ');
    cr_assert_str_eq(array[0]->str, "Hello");
    cr_assert_str_eq(array[1]->str, "World");
    cr_assert_str_eq(array[2]->str, "salut");
    cr_assert_str_eq(array[3]->str, "les");
    cr_assert_str_eq(array[4]->str, "amis");
    cr_assert_eq(array[5], NULL);
    string_destroy(&s);
}

Test(str, split_s_NULL)
{
    string_t **array;
    string_t s;

    string_init(&s, "Hello World salut les amis");
    array = split_s(NULL, ' ');
    cr_assert_eq(array, NULL);
    string_destroy(&s);
}