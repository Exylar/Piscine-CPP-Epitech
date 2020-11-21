/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D09_2019_MAGE_HPP
#define CPP_D09_2019_MAGE_HPP

#include "Character.hpp"
#include <iostream>

class Mage : public virtual Character {
    public:
        Mage(const std::string &name, int level);
        int CloseAttack();
        int RangeAttack();
        void RestorePower();
};

#endif //CPP_D09_2019_MAGE_HPP
