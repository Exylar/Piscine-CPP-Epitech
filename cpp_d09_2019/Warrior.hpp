/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D09_2019_WARRIOR_HPP
#define CPP_D09_2019_WARRIOR_HPP

#include "Character.hpp"
#include <iostream>

class Warrior : public virtual Character {
    public:
        Warrior(const std::string &name, int level);
        int CloseAttack();
        int RangeAttack();
    protected:
        std::string _weaponName = "hammer";
};

#endif //CPP_D09_2019_WARRIOR_HPP
