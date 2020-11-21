/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *sickKoala) {
    _content = sickKoala;
    _next = NULL;
}

bool SickKoalaList::isEnd()
{
    if (_next == NULL)
        return false;
    return true;
}

void SickKoalaList::append(SickKoalaList *sickKoalaList)
{
    if (_next == NULL)
        _next = sickKoalaList;
    else
        getNext()->append(sickKoalaList);

}

SickKoala *SickKoalaList::getFromName(std::string name)
{
    if (_content->getName() == name)
        return _content;
    else if (_next != NULL) {
        return getNext()->getFromName(name);
    }
    return NULL;
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *sickKoalaList)
{
    sickKoalaList = sickKoalaList;
    return this;
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    name = name;
    return this;
}

SickKoala *SickKoalaList::getContent()
{
    return _content;
}

SickKoalaList *SickKoalaList::getNext()
{
    return _next;
}

void SickKoalaList::dump()
{
    SickKoalaList *actual = this;

    std::cout << "Patients: ";
    while (actual->_next) {
        if (actual->getContent()->getName() != "")
            std::cout << actual->getContent()->getName() << ", ";
        else
            std::cout << "nullptr, ";
        actual = actual->getNext();
    }
    std::cout << actual->getContent()->getName() << "." << std::endl;
}