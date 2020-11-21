/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Character.hpp"

Character::Character(const std::string &name) : _name(name), _AP(40) {
    this->_weapon = NULL;
}

Character::~Character() {}

void Character::equip(AWeapon *weapon) {
    this->_weapon = weapon;
}

void Character::recoverAP()
{
    if (this->_AP < 30)
        this->_AP  = this->_AP + 10;
    else
        this->_AP = 40;
}

void Character::attack(AEnemy *enemy)
{
    if (!enemy || !this->_weapon)
        return;
    if (this->_AP >= this->_weapon->getAPCost()) {
        std::cout << _name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
        this->_weapon->Attack();
        enemy->takeDamage(this->_weapon->getDamage());
        this->_AP = this->_AP - this->_weapon->getAPCost();
        if (enemy->getHP() <= 0)
            delete enemy;
    }

}

const std::string & Character::getName() const
{
    return this->_name;
}

int Character::getAp() const
{
    return this->_AP;
}

AWeapon* Character::getWeapon() const
{
    return _weapon;
}

std::ostream &operator<<(std::ostream &out, const Character &character) {
    if (character.getWeapon() != NULL)
        out << character.getName() << " has " << character.getAp() << " AP and wields a " << character.getWeapon()->getName() << std::endl;
    else
        out << character.getName() << " has " << character.getAp() << " AP and is unarmed" << std::endl;
    return out;
}