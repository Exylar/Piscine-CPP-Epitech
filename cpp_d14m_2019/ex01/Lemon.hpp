/*
** EPITECH PROJECT, 2019
** cpp_d14m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D14M_2019_LEMON_HPP
#define CPP_D14M_2019_LEMON_HPP

#include "Fruit.hpp"

class Lemon : public Fruit {
    public:
        Lemon();
        Lemon(const std::string &name, int vitamins);
        virtual ~Lemon();
};

#endif //CPP_D14M_2019_LEMON_HPP
