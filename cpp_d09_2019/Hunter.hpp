/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D09_2019_HUNTER_HPP
#define CPP_D09_2019_HUNTER_HPP

#include "Character.hpp"
#include "Warrior.hpp"

class Hunter : public virtual Character, protected Warrior {
    public:
        Hunter(const std::string &name, int level);
        using Warrior::CloseAttack;
        int RangeAttack();
        void RestorePower();
};

#endif //CPP_D09_2019_HUNTER_HPP
