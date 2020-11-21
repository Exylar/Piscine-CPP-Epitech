/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D15_2019_EX00_HPP
#define CPP_D15_2019_EX00_HPP

#include <utility>
#include <string>

template<typename T>
void swap(T &a, T &b)
{
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

template<typename T>
T min(T &a, T &b)
{
    return (a < b) ? a : b;
}

template<typename T>
T max(T &a, T &b)
{
    return (a <= b) ? b : a;
}

template<typename T>
T add(T &a, T &b)
{
    return a + b;
}

#endif //CPP_D15_2019_EX00_HPP
