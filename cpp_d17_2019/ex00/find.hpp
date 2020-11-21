/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D17_2019_FIND_HPP
#define CPP_D17_2019_FIND_HPP

#include <algorithm>
#include <iterator>
#include <vector>

template <typename T>
auto do_find(T &value , int count)
{
    return std::find(value.begin(), value.end(), count);
}

#endif //CPP_D17_2019_FIND_HPP
