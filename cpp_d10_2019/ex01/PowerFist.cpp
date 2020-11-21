/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 50, 8) {}

PowerFist::~PowerFist() {};

void PowerFist::Attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}