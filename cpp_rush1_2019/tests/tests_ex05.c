/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 05
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "../array.h"
#include "../int.h"
#include "../new.h"

Test(string, task05_new_int)
{
    Object *list = new(Array, 10, Int, 0);

    cr_assert(len(list) == 10);
    delete(list);
}

Test(string, task05_setitem_int)
{
    Object *list = new(Array, 10, Int, 0);
    char *new_str;

    setitem(list, 5, 12);
    setitem(list, 6, 13);

    new_str = str(getitem(list, 5));
    cr_assert_str_eq(new_str, "<Int (12)>");
    delete(list);
}

Test(string, task05_it_int)
{
    Object *list = new(Array, 10, Int, 0);
    Object *it = begin(list);
    Object *it_end = end(list);

    setitem(list, 5, 12);
    setitem(list, 8, 13);

    cr_expect(eq(it, it) == 1);
    cr_assert(lt(it, it_end) == 1);
    cr_assert(gt(it, it_end) == 0);
}

Test(string, task05_empty_int)
{
    Object *list = new(Array, 0, Int, 0);

    cr_assert(len(list) == 0);
}

Test(string, task05_setval_int)
{
    Object *list = new(Array, 10, Int, 0);
    Object *it = begin(list);
    char *new_str;
    char *snd_str;

    setval(it, 5);
    new_str = str(getval(it));
    incr(it);
    setval(it, 0);
    snd_str = str(getval(it));
    cr_assert_str_eq(new_str, "<Int (5)>");
    cr_assert_str_eq(snd_str, "<Int (0)>");
    delete(list);
}