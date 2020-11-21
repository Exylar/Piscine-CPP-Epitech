/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D09_2019_PRIEST_HPP
#define CPP_D09_2019_PRIEST_HPP

#include "Character.hpp"
#include "Mage.hpp"
#include <iostream>

class Priest : public virtual Mage {
    public:
        Priest(const std::string &name, int level);
        int CloseAttack();
        void Heal();
    private:
};

#endif //CPP_D09_2019_PRIEST_HPP
