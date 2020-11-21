/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** GiftPaper
*/

#include <iostream>
#include "GiftPaper.hpp"

GiftPaper::GiftPaper()
    : Wrap("GiftPaper")
{
    this->isOpened = true;
}

GiftPaper::~GiftPaper()
{
}

Object *GiftPaper::clone() const
{
    return new GiftPaper(*this);
}

bool GiftPaper::wrapMeThat(Object *object)
{
    if (this->content != nullptr) {
        std::cerr << "Cannot wrap into non-empty box." << std::endl;
        return false;
    }
    this->content = object;
    return true;
}

void GiftPaper::openMe()
{
    this->isOpened = true;
}

void GiftPaper::closeMe()
{
    this->isOpened = false;
}
