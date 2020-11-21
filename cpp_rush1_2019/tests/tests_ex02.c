/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** ex02
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "../object.h"
#include "../new.h"
#include "../point.h"
#include "../vertex.h"

Test(str, task02_test01_point)
{
    Object  *point = new(Point, 42, -42);

    cr_assert_str_eq(str(point), "<Point (42, -42)>");
    delete(point);
}

Test(str, task02_test03_point)
{
    Object  *point = new(Point, 0, -42);

    cr_assert_str_eq(str(point), "<Point (0, -42)>");
    delete(point);
}

Test(str, task02_test02_point)
{
    Object  *point = new(Point, 420, -420);

    cr_assert_str_eq(str(point), "<Point (420, -420)>");
    delete(point);
}

Test(str, task02_test01_vertex)
{
    Object  *vertex = new(Vertex, 3, 4, 5);

    cr_assert_str_eq(str(vertex), "<Vertex (3, 4, 5)>");
    delete(vertex);
}

Test(str, task02_test02_vertex)
{
    Object  *vertex = new(Vertex, 0, 1, 2);

    cr_assert_str_eq(str(vertex), "<Vertex (0, 1, 2)>");
    delete(vertex);
}