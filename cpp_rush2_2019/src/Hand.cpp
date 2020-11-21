/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Hand
*/

#include "Hand.hpp"

Hand::Hand()
    : _obj(nullptr)
{
}

Hand::~Hand()
{
    if (this->_obj != nullptr)
        delete this->_obj;
}

void Hand::setObj(Object *newObj)
{
    if (this->_obj != nullptr) {
        std::cerr << "setObj: error: there is ";
        std::cerr << "something in that hand!" << std::endl;
        return;
    }
    this->_obj = newObj;
}

Object *Hand::getObj()
{
    Object *toReturn = this->_obj;

    this->_obj = nullptr;
    return toReturn;
}


Object *Hand::operator*()
{
    return this->_obj;
}

bool Hand::isEmpty() const
{
    return this->_obj == nullptr;
}