/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(str, copy)
{
    string_t s;
    char *buff = malloc(sizeof(char) * 7);
    string_t s2;

    string_init(&s, "Hello World salut les amis");
    string_init(&s2, "Bonsoir les copains");
    cr_assert_eq(copy(&s, buff, 7, 20), 7);
    string_destroy(&s);
    string_destroy(&s2);
}

Test(str, copy_buff_null)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello World salut les amis");
    string_init(&s2, "Bonsoir les copains");
    cr_assert_eq(copy(&s, NULL, 7, 10), 0);
    string_destroy(&s);
    string_destroy(&s2);
}