/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D10_2019_SUPERMUTANT_HPP
#define CPP_D10_2019_SUPERMUTANT_HPP

#include "AEnemy.hpp"
#include <iostream>

class SuperMutant : public AEnemy {
    public:
        SuperMutant();
        virtual ~SuperMutant();
        void takeDamage(int damage);
};

#endif //CPP_D10_2019_SUPERMUTANT_HPP
