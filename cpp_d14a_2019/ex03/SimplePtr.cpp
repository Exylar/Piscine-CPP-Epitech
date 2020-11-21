/*
** EPITECH PROJECT, 2019
** cpp_d14a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "SimplePtr.hpp"
#include <stdexcept>
#include "AtmosphereRegulator.hpp"
#include "WaterReclaimer.hpp"

SimplePtr::SimplePtr(SimplePtr const &) {}

SimplePtr::SimplePtr(BaseComponent *rawPtr) : _rawPtr(rawPtr) {}

SimplePtr::~SimplePtr() {
    delete _rawPtr;
}

BaseComponent* SimplePtr::get() const {
    return _rawPtr;
}

SimplePtr& SimplePtr::operator=(SimplePtr const &)
{
    return *this;
}