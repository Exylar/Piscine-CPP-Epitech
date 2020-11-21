/*
** EPITECH PROJECT, 2019
** cpp_d07a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Phaser.hpp"
#include "Sounds.hpp"
#include <iostream>

Phaser::Phaser(int maxAmmo, AmmoType type) : _maxAmmo(maxAmmo), _type(type) {}

Phaser::~Phaser() {}

void Phaser::fire()
{
    if (_currentAmmo[_type] <= Empty)
       std::cout << "Clip empty, please reload" << std::endl;
    else {
        _currentAmmo[_type] = _currentAmmo[_type] - 1;
        if (_type == REGULAR)
            std::cout << Sounds::Regular << std::endl;
        else if (_type == PLASMA)
            std::cout << Sounds::Plasma << std::endl;
        else if (_type == ROCKET)
            std::cout << Sounds::Rocket << std::endl;
    }
}

void Phaser::ejectClip()
{
    _currentAmmo[_type] = 0;
}

void Phaser::reload()
{
    std::cout << "Reloading..." << std::endl;
    _type = REGULAR;
    _currentAmmo[_type] = 20;
}

void Phaser::changeType(AmmoType newType)
{
    std::cout << "Switching ammo to type: ";
    _type = newType;
    if (newType == REGULAR)
        std::cout << "regular" << std::endl;
    else if (newType == PLASMA)
        std::cout << "plasma" << std::endl;
    else if (newType == ROCKET)
        std::cout << "rocket" << std::endl;
};

void Phaser::addAmmo(AmmoType type)
{
    _type = type;
    std::cout << "Clip full" << std::endl;
}

int Phaser::getCurrentAmmos() const
{
    return _currentAmmo[_type];
}