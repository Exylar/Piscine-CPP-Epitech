/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type) : _hp(hp), _type(type) {}

AEnemy::~AEnemy() {}

void AEnemy::takeDamage(int damage)
{
    if (damage >= 0)
        this->_hp = this->_hp - damage;
}

int AEnemy::getHP() const
{
    return this->_hp;
}

const std::string &AEnemy::getType() const
{
    return this->_type;
}