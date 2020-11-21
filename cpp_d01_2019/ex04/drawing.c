/*
** EPITECH PROJECT, 2019
** cpp_d01_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "drawing.h"

void draw_square(uint32_t **img, const point_t *point, size_t s, uint32_t c)
{
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++)
            img[point->x + i][point->y + j] = c;
    }
}