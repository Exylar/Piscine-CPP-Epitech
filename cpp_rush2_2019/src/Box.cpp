/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Box
*/

#include <iostream>
#include "Box.hpp"

Box::Box()
    : Wrap("Box")
{
}

Box::~Box()
{
}

Object *Box::clone() const
{
    return new Box(*this);
}

bool Box::wrapMeThat(Object *object)
{
    if (this->isOpened == false) {
        std::cerr << "Can't wrap into a closed box." << std::endl;
        return false;
    } else if (this->content != nullptr) {
        std::cerr << "Cannot wrap into non-empty box." << std::endl;
        return false;
    }
    this->content = object;
    return true;
}

void Box::openMe()
{
    this->isOpened = true;
}

void Box::closeMe()
{
    this->isOpened = false;
}
