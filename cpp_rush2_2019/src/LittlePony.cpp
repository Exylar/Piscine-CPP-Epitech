/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** LittlePony
*/

#include <iostream>
#include "LittlePony.hpp"

LittlePony::LittlePony(const std::string &title)
    : Toy(title)
{
}

LittlePony::~LittlePony()
{
}

void LittlePony::isTaken() const
{
    std::cout << "yo man" << std::endl;
}


Object *LittlePony::clone() const
{
    return new LittlePony(*this);
}
