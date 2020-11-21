/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D10_2019_SQUAD_HPP
#define CPP_D10_2019_SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include <iostream>

class Squad {
    public:
        Squad();
        virtual ~Squad();
        int getCount() const;
        ISpaceMarine* getUnit(int index) const;
        int push(ISpaceMarine *unit);
    protected:
        ISpaceMarine **squad;
};

#endif //CPP_D10_2019_SQUAD_HPP
