/*
** EPITECH PROJECT, 2019
** cpp_d07a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D07A_2019_PHASER_HPP
#define CPP_D07A_2019_PHASER_HPP

#include "Sounds.hpp"
#include <string>
#include <iostream>

class Phaser
{
    public:
        enum AmmoType
        {
            REGULAR = 0,
            PLASMA,
            ROCKET,
        };

    Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
        ~Phaser();
        void fire();
        void ejectClip();
        void changeType(AmmoType newType);
        void reload();
        void addAmmo(AmmoType type);
        int getCurrentAmmos() const;
    private:
        static const int Empty = 0;
        const int _maxAmmo;
        int _currentAmmo[3];
        AmmoType _type;
};

#endif //CPP_D07A_2019_PHASER_HPP
