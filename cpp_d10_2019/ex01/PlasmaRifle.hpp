/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D10_2019_PLASMARIFLE_HPP
#define CPP_D10_2019_PLASMARIFLE_HPP

#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
    public:
        PlasmaRifle();
        virtual ~PlasmaRifle();
        virtual void Attack() const;
};

#endif //CPP_D10_2019_PLASMARIFLE_HPP
