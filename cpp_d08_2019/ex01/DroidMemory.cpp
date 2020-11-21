/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "DroidMemory.hpp"
#include "ctime"

DroidMemory::DroidMemory() {
    this->_Fingerprint = rand();
}

DroidMemory::~DroidMemory() {}

size_t DroidMemory::getExp() const {
    return _Exp;
}

size_t DroidMemory::getFingerprint() const {
    return _Fingerprint;
}

void DroidMemory::setExp(size_t exp) {
    _Exp = exp;
}

void DroidMemory::setFingerprint(size_t fingerprint) {
    _Fingerprint = fingerprint;
}

DroidMemory& DroidMemory::operator<<(DroidMemory &droidMemory)
{
    this->setExp(_Exp + droidMemory.getExp());
    this->setFingerprint(droidMemory._Fingerprint ^ this->_Fingerprint);
    return *this;
}

DroidMemory& DroidMemory::operator>>(DroidMemory &droidMemory) {
    droidMemory.setExp(droidMemory.getExp() + _Exp);
    droidMemory.setFingerprint(this->_Fingerprint ^ droidMemory._Fingerprint);
    return droidMemory;
}

DroidMemory& DroidMemory::operator+=(DroidMemory &droidMemory) {
    this->setExp(_Exp + droidMemory.getExp());
    this->setFingerprint(droidMemory._Fingerprint ^ this->_Fingerprint);
    return *this;
}

DroidMemory& DroidMemory::operator+=(size_t xp) {
    if (xp < 2147483647)
        this->setExp(_Exp + xp);
    this->setFingerprint(this->_Fingerprint ^ xp);
    return *this;
}

DroidMemory& DroidMemory::operator+(DroidMemory &droidMemory)
{
    DroidMemory *new_memory = new DroidMemory();
    new_memory->operator+=(_Exp + droidMemory._Exp);
    return *new_memory;
}

DroidMemory& DroidMemory::operator+(size_t xp)
{
    if (xp < 2147483647)
        this->setExp(_Exp + xp);
    this->setFingerprint(this->_Fingerprint ^ xp);
    return *this;
}

std::ostream &operator<<(std::ostream &out, const DroidMemory &droidMemory) {
    std::cout << "DroidMemory '" << droidMemory.getFingerprint() << "', " << droidMemory.getExp();
    return out;
}