/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Victim.hpp"
#include "Peon.hpp"
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}

void Sorcerer::polymorph(const Peon &peon) const
{
    peon.getPolymorphed();
}

std::string Sorcerer::getName() const
{
    return this->_name;
}

std::string Sorcerer::getTitle() const
{
    return this->_title;
}

void Sorcerer::setName(std::string name)
{
    this->_name = name;
}

void Sorcerer::setTitle(std::string title)
{
    this->_title = title;
}

std::ostream &operator<<(std::ostream &out, const Sorcerer &sorcerer) {
    out << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!" << std::endl;
    return out;
}
