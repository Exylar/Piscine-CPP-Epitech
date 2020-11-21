/*
** EPITECH PROJECT, 2019
** cpp_d01_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "../include/menger.h"
#include "../include/drawing.h"

unsigned int get_color(int level)
{
    uint32_t color = 0;

    for (int16_t i = 2; i >= 0; --i)
        color |= (255 / level) << (i * 8);
    return color;
}

int menger(unsigned int **img, dims_t dims, int x, int y)
{
    point_t pts;

    dims.size = dims.size / 3;
    pts.y = dims.size + y;
    pts.x = dims.size + x;
    draw_square(img, &pts, dims.size, get_color(dims.level));
    if ((dims.level > 1) && (dims.size / 3) > 0) {
        dims.level = dims.level - 1;
        menger(img, dims, x, y);
        menger(img, dims, x, y + dims.size);
        menger(img, dims, x, y + (2 * dims.size));
        menger(img, dims, x + dims.size, y);
        menger(img, dims, x + dims.size, y + (2 * dims.size));
        menger(img, dims, x + (2 * dims.size), y);
        menger(img, dims, x + (2 * dims.size), y + dims.size);
        menger(img, dims, x + (2 * dims.size), y + (2 * dims.size));
    }
    return 0;
}