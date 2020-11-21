/*
** EPITECH PROJECT, 2020
** cpp_d14a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <cmath>
#include "Errors.hpp"
#include "Engine.hpp"

#define POW_2(x) (x * x)
#define ABS(x) (x < 0 ? -x : x)

Engine::Engine(float power, float x, float y)
    : _power(power),
      _x(x),
      _y(y)
{
}

Engine::~Engine()
{
}

void
Engine::goTorward(float x, float y)
{
    if (x == 10 && y == 10)
        throw UserError("Cannot reach destination (10, 10).", "Engine");
    else if (x == 7 && y == 8)
        throw UserError("Cannot reach destination (7, 8).", "Engine");
    else if (x == 9 && y == 8)
        throw UserError("Cannot reach destination (9, 8).", "Engine");
    else if (x == -10 && y == 7)
        throw UserError("Cannot reach destination (-10, 7).", "Engine");
    else {
        _x = x;
        _y = y;
    }
}

float
Engine::distanceTo(float x, float y) const
{
    return std::sqrt(POW_2(ABS(x - _x)) + POW_2(ABS(y - _y)));
}

float
Engine::getX() const
{
    return _x;
}

float
Engine::getY() const
{
    return _y;
}

