/*
** EPITECH PROJECT, 2019
** cpp_d01_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include "../include/drawing.h"
#include "../include/bitmap.h"
#include "../include/menger.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9') && (str[0] != '-'))
            return 0;
    }
    return 1;
}

int check_pow(int pow)
{
    if (pow == 1)
        return 1;
    if (pow >= 3)
        check_pow(pow / 3);
}

void create_image(int size, int level, unsigned int *buffer, unsigned int **img)
{
    dims_t dims;
    dims.size = size;
    dims.level = level;

    point_t p = {0, 0};
    initialize_image(size, buffer, img);
    draw_square(img, &p, size, get_color(255));
    menger(img, dims, 0, 0);
}

void create_bitmap_from_buffer(size_t size, char *name, unsigned int *buffer)
{
    int fd = open(strcat(name, ".bmp"), O_CREAT | O_TRUNC | O_WRONLY, 0644);
    write_bmp_header(fd, size);
    write_bmp_info_header(fd, size);
    write(fd, buffer, size * size * sizeof(*buffer));
    close(fd);
}

int main(int argc, char **argv)
{
    char* name;
    int size = 0;
    int level = 0;

    if (argc != 4) {
        fprintf(stderr, "menger_face file_name size level\n");
        exit(84);
    }
    if (my_str_isnum(argv[2]) == 0 || my_str_isnum(argv[3]) == 0)
        exit(84);
    name = strdup(argv[1]);
    size = atoi(argv[2]);
    level = atoi(argv[3]);
    if (check_pow(size) != 1)
        exit(84);
    unsigned int *buffer = malloc(size * size * sizeof(*buffer));
    unsigned int **img = malloc(size * sizeof(*img));
    create_image(size, level, buffer, img);
    create_bitmap_from_buffer(size, name, buffer);
    return EXIT_SUCCESS;
}