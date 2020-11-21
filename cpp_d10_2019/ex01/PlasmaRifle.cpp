/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 21, 5) {}

PlasmaRifle::~PlasmaRifle() {};

void PlasmaRifle::Attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}