/*
** EPITECH PROJECT, 2019
** cpp_d07a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks) : _name(name), _stimPaks(stimPaks) {}

Skat::Skat() : _name("bob"), _stimPaks(15){}

Skat::~Skat()
{
    _name = "";
    _stimPaks = 0;
}

int& Skat::stimPaks()
{
    return _stimPaks;
}

const std::string &Skat::name()
{
    return _name;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (_stimPaks >= number) {
        _stimPaks = _stimPaks - number;
        stock = stock + number;
        std::cout << "Keep the change." << std::endl;
    }
    else
        std::cout << "Don't be greedy" << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
}

void Skat::useStimPaks()
{
    if (_stimPaks > 0) {
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
        this->_stimPaks = _stimPaks - 1;
    }
    else
        std::cout << "Mediiiiiic" << std::endl;
}

void Skat::status()
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}