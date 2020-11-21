/*
** EPITECH PROJECT, 2019
** cpp_d02m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int cpt = 0;
    int **copy = malloc(sizeof(int *) * length);

    for (int i = 0; i < length; i++) {
        copy[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            copy[i][j] = tab[cpt];
            cpt++;
        }
    }
    *res = copy;
}