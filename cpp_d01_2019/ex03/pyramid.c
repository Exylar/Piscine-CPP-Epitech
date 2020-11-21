/*
** EPITECH PROJECT, 2019
** cpp_d01_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

int get_short_pyramid(int size, const int **map, int a, int b)
{
    int value_a = size > 1 ? get_short_pyramid(size - 1, map, a + 1, b) : 0;
    int value_b = size > 1 ? get_short_pyramid(size - 1, map, a + 1, b + 1) : 0;

    return map[a][b] + (value_a < value_b ? value_a : value_b);
}

int pyramid_path(int size, const int **map)
{
    return get_short_pyramid(size, map, 0, 0);
}