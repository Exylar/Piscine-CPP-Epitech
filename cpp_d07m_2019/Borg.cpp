/*
** EPITECH PROJECT, 2019
** cpp_d07m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Borg.hpp"
#include <iostream>

Borg::Ship::Ship() : _side(3000), _maxWarp(9), _location(UNICOMPLEX){
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core) {
    _core = core;
}

void Borg::Ship::checkCore()
{
    if (_core->_coreReactor->isStable())
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->_coreReactor->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move(int warp)
{
    if (warp <= _maxWarp && _home != _location && _core->_coreReactor->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

bool Borg::Ship::move(Destination d)
{
    if (d != _location && _core->_coreReactor->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move()
{
    if (_home != _location && _core->_coreReactor->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}
int Borg::Ship::getShield()
{
    return _shield;
}

void Borg::Ship::setShield(int shield)
{
    _shield = shield;
}

int Borg::Ship::getTorpedo()
{
    return _photonTorpedo;
}

void Borg::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}