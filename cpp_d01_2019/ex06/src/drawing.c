/*
** EPITECH PROJECT, 2019
** cpp_d01_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "../include/drawing.h"
#include "../include/bitmap.h"
#include <string.h>

void draw_square(uint32_t **img, const point_t *point, size_t s, uint32_t c)
{
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++)
            img[point->x + i][point->y + j] = c;
    }
}

void write_bmp_header(int fd, unsigned int size)
{
    bmp_header_t header;
    make_bmp_header(&header, size);
    write(fd, &header, sizeof(header));
}

void write_bmp_info_header(int fd, unsigned int size)
{
    bmp_info_header_t info;
    make_bmp_info_header(&info, size);
    write(fd, &info, sizeof(info));
}

void initialize_image(size_t size, unsigned int *buffer, unsigned int **img)
{
    memset(buffer, 0, size * size * sizeof(*buffer));
    for (size_t i = 0; i < size; ++ i)
        img[i] = buffer + i * size;
}
