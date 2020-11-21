/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level) : Character(name, level) {
    this->_class = "Mage";
    this->_race = "Gnome";
    this->_strength = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agility = 7;
    std::cout << name << " teleported" << std::endl;
}

int Mage::CloseAttack()
{
    if (this->_power >= 10) {
        this->_power = this->_power - 10;
        std::cout << this->_name << " blinks" << std::endl;
        this->Range = RANGE;
    }
    else
        std::cout << this->_name << " out of power" << std::endl;
    return 0;
}

int Mage::RangeAttack()
{
    if (this->_power >= 25) {
        this->_power = this->_power - 25;
        std::cout << this->_name << " launches a fire ball" << std::endl;
        return (20 + this->_spirit);
    }
    std::cout << this->_name << " out of power" << std::endl;
    return 0;
}

void Mage::RestorePower()
{
    if ((this->_power + (50 + this->_intelligence)) < 100)
        this->_power = this->_power + (50 + this->_intelligence);
    else
        this->_power = 100;
    std::cout << this->_name << " takes a mana potion" << std::endl;
}