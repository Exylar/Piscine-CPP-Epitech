/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Object
*/

#include "Object.hpp"

Object::Object(const std::string &title)
    : title(title)
{
}

Object::~Object()
{
}

const std::string &Object::getTitle() const
{
    return this->title;
}
