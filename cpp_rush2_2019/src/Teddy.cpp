/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Teddy
*/

#include <iostream>
#include "Teddy.hpp"

Teddy::Teddy(const std::string &title)
    : Toy(title)
{
}

Teddy::~Teddy()
{
}

void Teddy::isTaken() const
{
    std::cout << "gra hu" << std::endl;
}

Object *Teddy::clone() const
{
    return new Teddy(*this);
}
