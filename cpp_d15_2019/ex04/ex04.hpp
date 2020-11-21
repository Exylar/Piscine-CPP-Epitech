/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D15_2019_EX04_HPP
#define CPP_D15_2019_EX04_HPP

template <typename T>
bool equal(const T &a, const T &b) {
    return a == b;
}

template <class T>
class Tester {
    public:
        bool equal(const T &a, const T&b);
    protected:
        T _data;
};

#endif //CPP_D15_2019_EX04_HPP
