/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level) : Character(name, level),  Mage(name, level)
{
    this->_class = "Priest";
    this->_race = "Orc";
    this->_strength = 4;
    this->_stamina = 4;
    this->_intelligence = 42;
    this->_spirit = 21;
    this->_agility = 2;
    std::cout << name << " enters in the order" << std::endl;
}

int Priest::CloseAttack()
{
    if (this->_power >= 10) {
        this->_power = this->_power - 10;
        std::cout << this->_name  << " uses a spirit explosion" << std::endl;
        this->Range = Character::RANGE;
        return (10 + this->_spirit);
    }
    std::cout << this->_name << " out of power" << std::endl;
    return 0;
}

void Priest::Heal()
{
    if (this->_power >= 10) {
        this->_power = this->_power - 10;
        if (this->_health >= 30)
            this->_health = 100;
        else
            this->_health = this->_health + 70;
        std::cout << this->_name << " casts a little heal spell" << std::endl;
    } else
        std::cout << this->_name << " out of power" << std::endl;
}