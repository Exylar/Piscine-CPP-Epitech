/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 04
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "../object.h"
#include "../new.h"
#include "../point.h"
#include "../vertex.h"
#include "../int.h"
#include "../float.h"
#include "../char.h"


Test(str, task04_add01_int)
{
    Object  *p1 = new(Int, 12);
    Object  *p2 = new(Int, 2);

    cr_assert_str_eq(str(addition(p1, p2)), "<Int (14)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_add02_int)
{
    Object  *p1 = new(Int, 12);
    Object  *p2 = new(Int, 3);

    cr_assert_str_eq(str(addition(p1, p2)), "<Int (15)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_sub01_int)
{
    Object  *p1 = new(Int, -42);
    Object  *p2 = new(Int, 42);

    cr_assert_str_eq(str(subtraction(p1, p2)), "<Int (-84)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_sub02_int)
{
    Object  *p1 = new(Int, 96);
    Object  *p2 = new(Int, 3);

    cr_assert_str_eq(str(subtraction(p1, p2)), "<Int (93)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_mul01_int)
{
    Object  *p1 = new(Int, 12);
    Object  *p2 = new(Int, 2);

    cr_assert_str_eq(str(multiplication(p1, p2)), "<Int (24)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_mul02_int)
{
    Object  *p1 = new(Int, 12);
    Object  *p2 = new(Int, 3);

    cr_assert_str_eq(str(multiplication(p1, p2)), "<Int (36)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_div01_int)
{
    Object  *p1 = new(Int, 100);
    Object  *p2 = new(Int, 2);

    cr_assert_str_eq(str(division(p1, p2)), "<Int (50)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_div02_int)
{
    Object  *p1 = new(Int, 12, 13);
    Object  *p2 = new(Int, 2, 2);

    cr_assert_str_eq(str(division(p1, p2)), "<Int (6)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_eq_int)
{
    Object  *p1 = new(Int, 12);
    Object  *p2 = new(Int, 12);

    cr_expect(eq(p1, p2) == 1);
    delete(p1);
    delete(p2);
}

Test(str, task04_lt_int)
{
    Object  *p1 = new(Int, 14);
    Object  *p2 = new(Int, 42);

    cr_expect(lt(p1, p2) == 1);
    delete(p1);
    delete(p2);
}

Test(str, task04_gt_int)
{
    Object  *p1 = new(Int, 42);
    Object  *p2 = new(Int, 1);

    cr_expect(gt(p1, p2) == 1);
    delete(p1);
    delete(p2);
}

Test(str, task04_add01_float)
{
    Object  *p1 = new(Float, 12.000000);
    Object  *p2 = new(Float, 2.000000);

    cr_assert_str_eq(str(addition(p1, p2)), "<Float (14.000000)>");
    delete(p1);
    delete(p2);
}


Test(str, task04_add02_float)
{
    Object  *p1 = new(Float, 12.000000);
    Object  *p2 = new(Float, 3.000000);

    cr_assert_str_eq(str(addition(p1, p2)), "<Float (15.000000)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_sub01_float)
{
    Object  *p1 = new(Float, -42.000000);
    Object  *p2 = new(Float, 42.000000);

    cr_assert_str_eq(str(subtraction(p1, p2)), "<Float (-84.000000)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_sub02_float)
{
    Object  *p1 = new(Float, 96.000000);
    Object  *p2 = new(Float, 3.000000);

    cr_assert_str_eq(str(subtraction(p1, p2)), "<Float (93.000000)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_mul01_float)
{
    Object  *p1 = new(Float, 1.000000);
    Object  *p2 = new(Float, 2.00000);

    cr_assert_str_eq(str(multiplication(p1, p2)), "<Float (2.000000)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_mul02_float)
{
    Object  *p1 = new(Float, 12.000000);
    Object  *p2 = new(Float, 3.00000);

    cr_assert_str_eq(str(multiplication(p1, p2)), "<Float (36.000000)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_div01_float)
{
    Object  *p1 = new(Float, 100.000000);
    Object  *p2 = new(Float, 2.000000);

    cr_assert_str_eq(str(division(p1, p2)), "<Float (50.000000)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_div02_float)
{
    Object  *p1 = new(Float, 12.000000);
    Object  *p2 = new(Float, 2.000000);

    cr_assert_str_eq(str(division(p1, p2)), "<Float (6.000000)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_eq_float)
{
    Object  *p1 = new(Float, 14.000000);
    Object  *p2 = new(Float, 14.000000);

    cr_expect(eq(p1, p2) == 1);
    delete(p1);
    delete(p2);
}

Test(str, task04_lt_float)
{
    Object  *p1 = new(Float, 14.000000);
    Object  *p2 = new(Float, 42.000000);

    cr_expect(lt(p1, p2) == 1);
    delete(p1);
    delete(p2);
}

Test(str, task04_gt_float)
{
    Object  *p1 = new(Float, 42.000000);
    Object  *p2 = new(Float, 1.000000);

    cr_expect(gt(p1, p2) == 1);
    delete(p1);
    delete(p2);
}

Test(str, task04_add01_char)
{
    Object  *p1 = new(Char, 64);
    Object  *p2 = new(Char, 1);

    cr_assert_str_eq(str(addition(p1, p2)), "<Char (A)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_add02_char)
{
    Object  *p1 = new(Char, 69);
    Object  *p2 = new(Char, 7);

    cr_assert_str_eq(str(addition(p1, p2)), "<Char (L)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_sub01_char)
{
    Object  *p1 = new(Char, 64);
    Object  *p2 = new(Char, 1);

    cr_assert_str_eq(str(subtraction(p1, p2)), "<Char (?)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_sub02_char)
{
    Object  *p1 = new(Char, 69);
    Object  *p2 = new(Char, 7);

    cr_assert_str_eq(str(subtraction(p1, p2)), "<Char (>)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_mul01_char)
{
    Object  *p1 = new(Char, 64);
    Object  *p2 = new(Char, 1);

    cr_assert_str_eq(str(multiplication(p1, p2)), "<Char (@)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_mul02_char)
{
    Object  *p1 = new(Char, 40);
    Object  *p2 = new(Char, 2);

    cr_assert_str_eq(str(multiplication(p1, p2)), "<Char (P)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_div01_char)
{
    Object  *p1 = new(Char, 64);
    Object  *p2 = new(Char, 1);

    cr_assert_str_eq(str(division(p1, p2)), "<Char (@)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_div02_char)
{
    Object  *p1 = new(Char, 120);
    Object  *p2 = new(Char, 2);

    cr_assert_str_eq(str(division(p1, p2)), "<Char (<)>");
    delete(p1);
    delete(p2);
}

Test(str, task04_eq_char)
{
    Object  *p1 = new(Char, 'A');
    Object  *p2 = new(Char, 'A');

    cr_expect(eq(p1, p2) == 1);
    delete(p1);
    delete(p2);
}

Test(str, task04_lt_char)
{
    Object  *p1 = new(Char, 'a');
    Object  *p2 = new(Char, 'z');
    cr_expect(lt(p1, p2) == 1);
    delete(p1);
    delete(p2);
}

Test(str, task04_gt_char)
{
    Object  *p1 = new(Char, 'a');
    Object  *p2 = new(Char, 'z');

    cr_expect(gt(p1, p2) == 0);
    delete(p1);
    delete(p2);
}