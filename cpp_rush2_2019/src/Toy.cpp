/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(const std::string &title)
    : Object(title)
{
}

Toy::~Toy()
{
}

bool Toy::canWrap() const
{
    return false;
}
