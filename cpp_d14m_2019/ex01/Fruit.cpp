/*
** EPITECH PROJECT, 2019
** cpp_d14m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Fruit.hpp"

Fruit::Fruit() {}

Fruit::Fruit(const std::string &name, int vitamins) : _name(name), _vitamins(vitamins) {}

Fruit::~Fruit() {}

Fruit& Fruit::operator=(const Fruit &fruit)
{
    this->_name = fruit._name;
    this->_vitamins = fruit._vitamins;
    return *this;
}


std::string Fruit::getName() const
{
    return this->_name;
}

int Fruit::getVitamins() const
{
    return this->_vitamins;
}

void Fruit::setName(const std::string name)
{
    this->_name = name;
}

void Fruit::setVitamins(int vitamins)
{
    this->_vitamins = vitamins;
}