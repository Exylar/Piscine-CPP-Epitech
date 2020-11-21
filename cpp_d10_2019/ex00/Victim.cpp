/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Victim.hpp"

Victim::Victim(std::string name) : _name(name)
{
    std::cout << "Some random victim called " << name << " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl;
}

void Victim::getPolymorphed() const
{

    std::cout << this->_name << " has been turned into a cute little sheep!" << std::endl;
}

std::string Victim::getName() const
{
    return this->_name;
}

void Victim::setName(std::string name)
{
    this->_name = name;
}

std::ostream &operator<<(std::ostream &out, const Victim &victim) {
    out << "I'm " << victim.getName() << " and I like otters!" << std::endl;
    return out;
}