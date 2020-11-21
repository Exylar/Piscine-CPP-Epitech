/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Hunter.hpp"
#include "Warrior.hpp"

Hunter::Hunter(const std::string &name, int level) : Character(name, level), Warrior(name ,level) {
    this->_class = "Hunter";
    this->_race = "Elf";
    this->_strength = 9;
    this->_stamina = 9;
    this->_intelligence = 5;
    this->_spirit = 6;
    this->_agility = 25;
    this->_weaponName = "sword";
    std::cout << name << " is born from a tree" << std::endl;
}

int Hunter::RangeAttack()
{
    if (this->_power >= 25) {
        this->_power = this->_power - 25;
        std::cout << this->_name << " uses his bow" << std::endl;
        return (20 + this->_agility);
    }
    std::cout << this->_name << " out of power" << std::endl;
    return 0;
}

void Hunter::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " meditates" << std::endl;
}