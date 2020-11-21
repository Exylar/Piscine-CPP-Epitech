/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D15_2019_EX02_HPP
#define CPP_D15_2019_EX02_HPP

#include <iostream>

template <typename T>
T min (T const &num1, T const &num2) {
    std::cout << "template min" << std::endl;
    return (num1 <= num2) ? num1 : num2;
}

int min (int num1, int num2) {
    std::cout << "non-template min" << std::endl;
    return (num1 <= num2) ? num1 : num2;
}

template <typename T>
T templateMin(T const *tab, int const &n) {
    std::cout << "template min" << std::endl;
    T small = tab[0];
    int i = 0;
    while (i < n) {
        if (small > tab[i])
            small = tab[i];
        i++;
    }
    return small;
}

int nonTemplateMin(const int *array, const int count) {
    std::cout << "non-template min" << std::endl;
    int small = array[0];
    int i = 0;
    while (i < count) {
        if (small > array[i])
            small = array[i];
        i++;
    }
    return small;
}

#endif //CPP_D15_2019_EX02_HPP