/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level) : Character(name, level), Warrior(name, level), Mage(name, level), Priest(name, level)
{
    this->Warrior::_class = "Paladin";
    this->Warrior::_race = "Human";
    this->Warrior::_strength = 9;
    this->Warrior::_stamina = 10;
    this->Warrior::_intelligence = 10;
    this->Warrior::_spirit = 10;
    this->Warrior::_agility = 2;
    this->_weaponName = "hammer";
    std::cout << "the light falls on " << name << std::endl;
}

int Paladin::Intercept()
{
    return Warrior::RangeAttack();
}