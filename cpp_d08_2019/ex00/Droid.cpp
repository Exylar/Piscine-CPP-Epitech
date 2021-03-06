/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Droid.hpp"

Droid::Droid(std::string id) : _Id(id) {
    std::cout << "Droid '" << _Id << "' Activated" << std::endl;
}

Droid::Droid() {
    std::cout << "Droid '" << _Id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &droid) {
    this->_Id = droid._Id;
    this->_Energy = droid._Energy;
    this->_Status = *droid.getStatus();
    std::cout << "Droid '" << _Id << "' Activated, Memory Dumped" << std::endl;
}

Droid &Droid::operator=(const Droid &droid) {
    this->_Energy = droid._Energy;
    this->_Status = *droid.getStatus();
    this->_Id = droid._Id;
    return *this;
}

Droid::~Droid() {
    std::cout << "Droid '" << _Id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const {
    return _Id;
}

size_t Droid::getAttack() const {
    return _Attack;
}

size_t Droid::getEnergy() const {
    return _Energy;
}

size_t Droid::getToughness() const {
    return _Toughness;
}

std::string *Droid::getStatus() const {
    return new std::string(_Status);
}

void Droid::setId(std::string id) {
    _Id = id;
}

void Droid::setStatus(std::string *status) {
    _Status = *status;
}

void Droid::setEnergy(size_t energy) {
    if (energy <= 100)
        this->_Energy = energy;
}

Droid &Droid::operator<<(size_t &energy) {
    int value = 0;

    if (energy < 2147483647) {
        if (_Energy + energy >= 100) {
            value = 100 - _Energy;
            this->setEnergy(100);
            energy = energy - value;
        } else {
            this->setEnergy(_Energy + energy);
            energy = 0;
        }
    }
    else {
        energy = 0;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Droid &droid) {
    out << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
    return out;
}

bool Droid::operator==(const Droid &droid) const {
    return (this->_Id == droid._Id && this->_Status == droid._Status && this->_Energy == droid._Energy);
}

bool Droid::operator!=(const Droid &droid) const {
    return !(*this == droid);
}
