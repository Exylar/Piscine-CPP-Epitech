/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D15_2019_EX01_HPP
#define CPP_D15_2019_EX01_HPP

template <typename T>
int compare(T const &a, T const &b)
{
    if (a == b)
        return 0;
    else if (a > b)
        return 1;
    else
        return -1;
};

template<>
int compare(char const &s1, char const &s2)
{
    if (s1 == s2)
        return 0;
    else if (s1 > s2)
        return 1;
    else
        return -1;
}

#endif //CPP_D15_2019_EX01_HPP
