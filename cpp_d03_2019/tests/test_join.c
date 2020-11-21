/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, join_c)
{
    string_t s;
    const char * const array[6] = {
        "Hello",
        "World",
        "salut",
        "les",
        "amis",
        NULL,
    };

    string_init(&s, "Test");
    join_c(&s, ' ', array);
    cr_assert_str_eq(s.str, "Hello World salut les amis");
    string_destroy(&s);
}

Test(str, join_c_NULL)
{
    string_t s;
    const char * const array[6] = {
        "Hello",
        "World",
        "salut",
        "les",
        "amis",
        NULL,
    };

    string_init(&s, "Test");
    join_c(NULL, ' ', array);
    cr_assert_str_eq(s.str, "Test");
    string_destroy(&s);
}

Test(str, join_s)
{
    string_t **array;
    string_t list;
    string_t s;

    string_init(&list, "Hello World salut les amis");
    array = split_s(&list, ' ');
    string_init(&s, "Test");
    join_s(&s, ' ', (const string_t * const*)array);
    cr_assert_str_eq(s.str, "Hello World salut les amis");
    string_destroy(&s);
    string_destroy(&list);
}

Test(str, join_s_null)
{
    string_t **array;
    string_t list;
    string_t s;

    string_init(&list, "Hello World salut les amis");
    array = split_s(&list, ' ');
    string_init(&s, "Test");
    join_s(NULL, ' ', (const string_t * const*)array);
    cr_assert_str_eq(s.str, "Test");
    string_destroy(&s);
    string_destroy(&list);
}