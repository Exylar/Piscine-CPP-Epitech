/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D15_2019_EX03_HPP
#define CPP_D15_2019_EX03_HPP

#include <iostream>


template <typename T>
void foreach(T *tab, void (&func)(T&),const int count) {
    for (int i = 0; i < count; i++)
        func(tab[i]);
}

template <typename T>
void print(T &elem) {
    std::cout << elem << std::endl;
}

#endif //CPP_D15_2019_EX03_HPP

