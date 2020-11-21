/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int damage, int apcost) : _name(name), _damage(damage), _ap_cost(apcost) {}

AWeapon::~AWeapon() {}

int AWeapon::getAPCost() const
{
    return this->_ap_cost;
}

int AWeapon::getDamage() const
{
    return this->_damage;
}

std::string AWeapon::getName() const
{
    return this->_name;
}

void AWeapon::setAPCost(int apcost)
{
    this->_ap_cost = apcost;
}

void AWeapon::setDamage(int damage)
{
    this->_damage = damage;
}

void AWeapon::setName(std::string name)
{
    this->_name = name;
}