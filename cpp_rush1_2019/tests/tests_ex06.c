/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 04
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "../int.h"
#include "../object.h"
#include "../new.h"
#include "../list.h"
#include "../container.h"

Test(string, task06_new_int)
{
    Object *list = new(List, 10, Int, 0);

    cr_assert(len(list) == 10);
    delete(list);
}

Test(string, task06_setitem_int)
{
    Object *list = new(List, 10, Int, 0);
    char *new_str;

    setitem(list, 5, 12);
    setitem(list, 6, 13);

    new_str = str(getitem(list, 5));
    cr_assert_str_eq(new_str, "<Int (12)>");
    delete(list);
}

Test(string, task06_it_int)
{
    Object *list = new(List, 10, Int, 0);
    Object *it = begin(list);
    Object *it_end = end(list);

    setitem(list, 5, 12);
    setitem(list, 8, 13);

    cr_expect(eq(it, it) == 1);
    cr_assert(lt(it, it_end) == 1);
    cr_assert(gt(it, it_end) == 0);
}

Test(string, task06_empty_int)
{
    Object *list = new(List, 0, Int, 0);

    cr_assert(len(list) == 0);
}

Test(string, task06_setval_int)
{
    Object *list = new(List, 10, Int, 0);
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

/*
int main(void)
{
    Object *list = new(List, 10, Int, 0);
    Object *it = begin(list);
    Object *it_end = end(list);

    printf("list size: %zu\n", len(list));

    setitem(list, 5, 12);
    setitem(list, 6, 13);
    setval(it, 42);
    printf("val begin: %s\n\n\n", str(getval(it)));
    while (lt(it, it_end)) {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
    printf("\nitem 5: %s\n", str(getitem(list, 5)));
    printf("item 8: %s\n", str(getitem(list, 8)));
    delete(it);
    delete(it_end);
    delete(list);
    printf("\n-------------------------------------------------\n\n");
    test_float();
    return (0);
} */