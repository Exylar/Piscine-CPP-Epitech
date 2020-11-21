/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level) : Character(name, level) {
    this->_class = "Warrior";
    this->_race = "Dwarf";
    this->_strength = 12;
    this->_stamina = 12;
    this->_intelligence = 6;
    this->_spirit = 5;
    this->_agility = 7;
    this->_weaponName = "hammer";
    std::cout << "I'm " << name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

int Warrior::CloseAttack()
{
    if (this->_power >= 30) {
        this->_power = this->_power - 30;
        std::cout << this->_name << " strikes with his " << _weaponName << std::endl;
        return (20 + this->_strength);
    }
    std::cout << this->_name << " out of power" << std::endl;
    return 0;
}

int Warrior::RangeAttack()
{
    if (this->_power >= 10) {
        this->_power = this->_power - 10;
        std::cout << this->_name << " intercepts" << std::endl;
        this->Range = Character::CLOSE;
    }
    else {
        std::cout << this->_name << " out of power" << std::endl;
    }
    return 0;
}