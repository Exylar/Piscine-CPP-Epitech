/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D10_2019_SPACEMARINE_HPP
#define CPP_D10_2019_SPACEMARINE_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class SpaceMarine {
    public:
        SpaceMarine();
        virtual ~SpaceMarine();
        SpaceMarine *clone();
        void battleCry() const;
        void rangedAttack() const;
        void melleAttack() const;

#endif //CPP_D10_2019_SPACEMARINE_HPP
