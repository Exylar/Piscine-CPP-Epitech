/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Squad.hpp"

Squad::Squad() {}

Squad::~Squad() {}

int Squad::getCount() const
{
    int count = 0;

    while (this->squad[count])
        count++;
    return count;
}

int Squad::getUnit(int index) const
{
    if (index <= this->getCount())
        return this->squad[index];
    return nullptr;
}

int Squad::push(ISpaceMarine *unit)
{
    if (unit == NULL)
        return getCount();
    return getCount();
}