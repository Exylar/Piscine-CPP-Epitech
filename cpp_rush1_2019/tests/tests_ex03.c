/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 03
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "../object.h"
#include "../new.h"
#include "../point.h"
#include "../vertex.h"

Test(str, task03_add_point)
{
    Object  *p1 = new(Point, 12, 13);
    Object  *p2 = new(Point, 2, 2);

    cr_assert_str_eq(str(addition(p1, p2)), "<Point (14, 15)>");
    delete(p1);
    delete(p2);
}

Test(str, task03_sub_point)
{
    Object  *p1 = new(Point, 12, 13);
    Object  *p2 = new(Point, 2, 2);

    cr_assert_str_eq(str(subtraction(p1, p2)), "<Point (10, 11)>");
    delete(p1);
    delete(p2);
}

Test(str, task03_add_vertex)
{
    Object  *v1 = new(Vertex, 1, 2, 3);
    Object  *v2 = new(Vertex, 4, 5, 6);

    cr_assert_str_eq(str(addition(v1, v2)), "<Vertex (5, 7, 9)>");
    delete(v1);
    delete(v2);
}

Test(str, task03_sub_vertex)
{
    Object  *v1 = new(Vertex, 1, 2, 3);
    Object  *v2 = new(Vertex, 4, 5, 6);

    cr_assert_str_eq(str(subtraction(v1, v2)), "<Vertex (-3, -3, -3)>");
    delete(v1);
    delete(v2);
}