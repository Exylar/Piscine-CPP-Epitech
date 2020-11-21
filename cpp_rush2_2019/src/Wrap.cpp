/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Wrap
*/

#include "Wrap.hpp"

Wrap::Wrap(const std::string &wrapTitle)
    : Object(wrapTitle), isOpened(false), content(nullptr)
{
}

Wrap::~Wrap()
{
}

void Wrap::isTaken() const
{
    std::cout << "whistles while working" << std::endl;
}

Object *Wrap::getContent()
{
    Object *obj;

    if (this->isOpened == false) {
        std::cerr << "The wrap is closed." << std::endl;
        return nullptr;
    }
    obj = this->content;
    this->content = nullptr;
    return obj;
}

bool Wrap::canWrap() const
{
    return true;
}
