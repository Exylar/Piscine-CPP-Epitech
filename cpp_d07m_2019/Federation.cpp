/*
** EPITECH PROJECT, 2019
** cpp_d07m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Borg.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp) : _length(length), _width(width), _name(name), _maxWarp(maxWarp)
{
    std::cout << "The ship USS " << name << " has been finished." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::Ship() {
    std::cout << "The ship USS Entreprise has been finished." << std::endl;
    std::cout << "It is 289 m in length and 132 m in width." << std::endl;
    std::cout << "It can go to Warp 6 !" << std::endl;
};

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core) {
    std::cout << "USS " << _name << ": The core is set." << std::endl;
    _core = core;
}

void Federation::Starfleet::Ship::checkCore()
{
    if (_core->_coreReactor->isStable())
        std::cout << "USS " << _name << ": The core is stable at the time." << std::endl;
    else
        std::cout << "USS " << _name << ": The core is unstable at the time." << std::endl;
}

void  Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captaine)
{
    _captaine = captaine;
    std::cout << _captaine->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;;
}

int Federation::Starfleet::Ship::getShield()
{
    return _shield;
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return _photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}
/*
void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (_photonTorpedo == 0)
        std::cout << _name << ": No enough torpedoes to fire, " << _captaine->getName() << "!" << endl;
    else {
        _photonTorpedo--;
        target->setShield(_shield - 50);
        std::cout << _name << ": Firing on target. " << _photonTorpedo
                  << " torpedoes remainning." << endl;
        if (_photonTorpedo == 0)
            std::cout << _name << ": No more torpedo to fire, "
                      << _captaine->getName() << "!" << endl;
    }
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    while (torpedoes > 0 && _photonTorpedo > 0) {
        torpedoes--;
        _photonTorpedo--;
        target->setShield(_shield - 50);
        std::cout << _name << ": Firing on target. " << torpedoes << " torpedoes remainning." << endl;
    }
    if (torpedoes == 0 && _photonTorpedo > 0)
        std::cout << _name << ": No more torpedo to fire, "
                  << _captaine->getName() << "!" << endl;
    else if (torpedoes > 0 && _photonTorpedo == 0)
        std::cout << _name << ": No enough torpedoes to fire, " << _captaine->getName() << "!" << endl;

} */

Federation::Ship::Ship(int length, int width, std::string name) : _length(length), _width(width), _name(name), _location(_home) {
    std::cout << "The independent ship " << name << " just finished its construction." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core) {
    std::cout << _name << ": The core is set." << std::endl;;
    _core = core;
}

void Federation::Ship::checkCore()
{
    if (_core->_coreReactor->isStable())
        std::cout << _name << ": The core is stable at the time." << std::endl;
    else
        std::cout << _name << ": The core is unstable at the time." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->_coreReactor->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= _maxWarp && _home != _location && _core->_coreReactor->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != _location && _core->_coreReactor->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move()
{
    if (_home != _location && _core->_coreReactor->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->_coreReactor->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int warp)
{
    if (warp <= _maxWarp && _home != _location && _core->_coreReactor->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(Destination d)
{
    if (d != _location && _core->_coreReactor->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move()
{
    if (_home != _location && _core->_coreReactor->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

int Federation::Ship::getShield()
{
    return _shield;
}

void Federation::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Ship::getTorpedo()
{
    return _photonTorpedo;
}

void Federation::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}


Federation::Starfleet::Captain::Captain(std::string name) : _name(name), _age(0) {}

int Federation::Starfleet::Captain::getAge()
{
    return _age;
}

std::string Federation::Starfleet::Captain::getName()
{
    return _name;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name) : _name(name) {
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;;
}