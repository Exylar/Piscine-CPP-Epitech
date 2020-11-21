/*
** EPITECH PROJECT, 2019
** cpp_d01_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D01_2019_EX05_H
#define CPP_D01_2019_EX05_H

#include <stdint.h>

typedef union bar_s{
    uint16_t bar;
    uint16_t foo;
} bar_t;

typedef union foo2_s{
    bar_t bar;
    uint32_t test;
    uint16_t foo;
} foo2_t;

typedef union foo_s {
    uint32_t bar;
    foo2_t foo;
} foo_t;

#endif //CPP_D01_2019_EX05_H
