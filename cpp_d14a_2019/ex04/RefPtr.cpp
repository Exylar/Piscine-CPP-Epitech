/*
** EPITECH PROJECT, 2019
** cpp_d14a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "RefPtr.hpp"

RefPtr::RefPtr(RefPtr const &other)
{
    this->_rawPtr = other._rawPtr;
}

RefPtr::RefPtr(BaseComponent *rawPtr) : _rawPtr(rawPtr) {}

RefPtr::~RefPtr() {
    delete _rawPtr;
}

BaseComponent* RefPtr::get() const
{
    return _rawPtr;
}

RefPtr& RefPtr::operator=(RefPtr const &other)
{
    this->_rawPtr = other._rawPtr;
    return *this;
}