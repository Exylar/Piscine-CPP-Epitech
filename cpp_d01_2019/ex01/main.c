/*
** EPITECH PROJECT, 2019
** cpp_d01_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "menger.h"

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

int main(int argc, char** argv)
{
    int size = 0;
    int level = 0;

    if (argc != 3)
        exit(84);
    if (my_str_isnum(argv[1]) == 0 || my_str_isnum(argv[2]) == 0)
        exit(84);
    size = atoi(argv[1]);
    level = atoi(argv[2]);
    if (check_pow(size) != 1)
        exit(84);
    menger(size, level, 0, 0);
}