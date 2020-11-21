/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 06
*/

#include <stdio.h>
#include "object.h"
#include "container.h"
#include "list.h"
#include "int.h"
#include "float.h"
#include "new.h"

void test_float(void)
{
    Object *list = new(List, 10, Float, 0.0f);
    Object *it = begin(list);
    Object *it_end = end(list);

    printf("list size: %zu\n", len(list));
    setitem(list, 2, 10.696969f);
    setitem(list, 3, 6.911911f);
    setitem(list, 4, 16.118218f);
    setitem(list, 5, 42.424242f);
    setval(it, 9.999999);
    printf("item 0 %s\n\n\n", str(getval(it)));
    while (lt(it, it_end)) {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
    printf("\nitem 2: %s\n", str(getitem(list, 2)));
    printf("item 3: %s\n", str(getitem(list, 3)));
    delete(it);
    delete(it_end);
    delete(list);
}

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
}