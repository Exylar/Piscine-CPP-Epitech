/*
** EPITECH PROJECT, 2020
** cpp_d14a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <iostream>
#include "Errors.hpp"
#include "Oxygenator.hpp"

Oxygenator::Oxygenator() : _quantity(0)
{
}

void
Oxygenator::generateOxygen()
{
    _quantity += 10;
}

void
Oxygenator::useOxygen(int quantity)
{
    if (_quantity - quantity < 10)
        throw LifeCriticalError("Not enough oxygen to live.", "Oxygenator");
    if (_quantity < 25)
        throw MissionCriticalError("Not enough oxygen to continue the mission.", "Oxygenator");
    _quantity -= quantity;
}
