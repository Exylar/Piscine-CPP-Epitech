/*
** EPITECH PROJECT, 2019
** cpp_d01_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D01_2019_DRAWING_H
#define CPP_D01_2019_DRAWING_H

#include <stdint.h>
#include <stddef.h>

typedef struct point_s {
    unsigned int x;
    unsigned int y;
} point_t;

void draw_square(uint32_t **img, const point_t *point, size_t s, uint32_t c);
unsigned int get_color(int level);
void write_bmp_header(int fd, unsigned int size);
void write_bmp_info_header(int fd, unsigned int size);
void initialize_image(size_t size, unsigned int *buffer, unsigned int **img);

#endif //CPP_D01_2019_DRAWING_H
