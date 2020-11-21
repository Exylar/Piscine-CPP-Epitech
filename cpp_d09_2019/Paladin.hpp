/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D09_2019_PALADIN_HPP
#define CPP_D09_2019_PALADIN_HPP

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : virtual public Warrior, public Priest {
    public:
        Paladin(const std::string &name, int level);
        using Warrior::CloseAttack;
        using Warrior::RestorePower;
        using Priest::RangeAttack;
        using Priest::Heal;
        int Intercept();
};

#endif //CPP_D09_2019_PALADIN_HPP
