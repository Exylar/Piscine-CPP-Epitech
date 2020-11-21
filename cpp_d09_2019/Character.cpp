/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level) : _name(name), _level(level) {
    std::cout << name << " Created" << std::endl;
}

Character::~Character() {}


int Character::CloseAttack()
{
    if (this->_power >= 10) {
        this->_power = this->_power - 10;
        std::cout << this->_name << " strikes with a wooden stick" << std::endl;
        return (10 + this->_strength);
    }
    std::cout << this->_name << " out of power" << std::endl;
    return 0;
}

int Character::RangeAttack()
{
    if (this->_power >= 10) {
        this->_power = this->_power - 10;
        std::cout << this->_name << " tosses a stone" << std::endl;
        return (5 + this->_strength);
    }
    std::cout << this->_name << " out of power" << std::endl;
    return 0;
}

void Character::Heal()
{
    if (this->_health <= 50)
        this->_health = this->_health + 50;
    else
        this->_health = 100;
    std::cout << this->_name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    if (this->_health > damage) {
        this->_health = this->_health - damage;
        std::cout << this->_name << " takes " << damage << " damage" << std::endl;
    } else {
        this->_health = 0;
        std::cout << this->_name << " out of combat" << std::endl;
    }
}

const std::string & Character::getName() const {
    return _name;
}

int Character::getLvl() const {
    return _level;
}

int Character::getPower() const {
    return _power;
}

int Character::getPv() const {
    return _health;
}

Character::AttackRange Character::getRange() const {
    return Range;
}