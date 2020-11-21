/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <iostream>
#include "Carrier.hpp"

Carrier::Carrier(std::string id) : _Id(id) {}

Carrier::~Carrier() {}

Carrier& Carrier::operator<<(Droid *droid)
{
    int nb = 0;

    while (this->Droids[nb] != NULL && nb < 5 )
        nb++;
    if (nb == 5)
        return *this;
    this->Droids[nb] = droid;
    this->operator~();
    return *this;
}

Carrier& Carrier::operator>>(Droid *droid)
{
    int nb = 0;

    while (nb < 5) {
        if (this->Droids[nb] != NULL) {
            if (this->Droids[nb] == droid) {
                this->Droids[nb] = NULL;
                if (nb >= 1)
                    this->_Speed = (100 - (nb * 10));
                else
                    this->_Speed = 0;
                break;
            }
        }
        nb++;
    }
    return *this;
}

void Carrier::operator<<(Droid *droid)
{
    int max = 0;

    if (this->_Energy == 600)
        return;
    else if ((this->_Energy + droid->getEnergy()) <= 600) {
        this->_Energy = this->_Energy + droid->getEnergy();
        droid->setEnergy(0);
    }
    else {
        max = 600 - this->_Energy;
        this->_Energy = 600;
        droid->setEnergy(100 - max);
    }
}

bool Carrier::operator()(int x, int y)
{
    int nb = this->getCount();
    size_t consume = 0;

    if (x < 0)
        x = -x;
    if (y < 0)
        y = -y;

    consume = (size_t)((x + y) * (10 + nb));

    if (this->_Energy >= consume && consume <= 600 && this->_Speed == 0) {
        this->_Energy = this->_Energy - ((x + y) * (10 + nb));
        return true;
    }
    else
        return false;
}

Droid &Carrier::operator[](int nb) const {
    return *this->Droids[nb];
}

const Droid& Carrier::operator[](size_t const nb) const
{
    return *this->Droids[nb];
}

Carrier& Carrier::operator~() {
    int nb = this->getCount();

    if (nb >= 1)
        this->_Speed = (100 - (nb * 10));
    else
        this->_Speed = 0;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Carrier &carrier) {
    std::cout << "Carrier '" << carrier.getId() << "', Droid(s) on-board:" << std::endl;
    for (int i = 0; i < 5; i++) {
        if (&carrier.operator[](i) != NULL)
            std::cout << "[" << i << "] : " << "Droid '" << carrier.operator[](i).getId() << "', " << *carrier.operator[](i).getStatus() << ", " << carrier.operator[](i).getEnergy() << std::endl;
        else
            std::cout << "[" << i << "] : " << "Free" << std::endl;
    }
    std::cout << "Speed : " << carrier.getSpeed() << ", Energy " << carrier.getEnergy();
    return out;
}

size_t Carrier::getCount() const {
    int nb = 0;

    for (int i = 0; i < 5; i++) {
        if (this->Droids[nb] != NULL) {
            nb++;
        }
    }
    return nb;
}

std::string Carrier::getId() const {
    return _Id;
}

size_t Carrier::getAttack() const {
    return _Attack;
}

size_t Carrier::getSpeed() const {
    return _Speed;
}

size_t Carrier::getEnergy() const {
    return _Energy;
}

size_t Carrier::getToughness() const {
    return _Toughness;
}

void Carrier::setId(std::string id) {
    this->_Id = id;
}

void Carrier::setSpeed(size_t speed) {
    if (speed <= 100)
        this->_Speed = speed;
}

void Carrier::setEnergy(size_t energy) {
    if (energy < 600) {
        this->_Energy = energy;
    }
}

void Carrier::setToughness(size_t toughness) {
    if (toughness <= 100)
        this->_Toughness = toughness;
}
