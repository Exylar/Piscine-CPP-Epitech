/*
** EPITECH PROJECT, 2019
** cpp_d01_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D01_2019_MENGER_H
#define CPP_D01_2019_MENGER_H

#include <stdlib.h>
#include <stdio.h>

typedef struct dims_s {
    int size;
    int level;
} dims_t;

int menger(unsigned int **img, dims_t dims, int x, int y);

#endif //CPP_D01_2019_MENGER_H
