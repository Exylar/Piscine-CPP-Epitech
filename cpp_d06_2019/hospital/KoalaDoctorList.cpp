/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *koalaDoctor)
{
    _content = koalaDoctor;
    _next = NULL;
}

bool KoalaDoctorList::isEnd()
{
    if (_next == NULL)
        return false;
    return true;
}

void KoalaDoctorList::append(KoalaDoctorList *koalaDoctorList)
{
    if (_next == NULL)
        _next = koalaDoctorList;
    else
        getNext()->append(koalaDoctorList);

}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    if (_content->getName() == name)
        return _content;
    else if (_next != NULL) {
        return getNext()->getFromName(name);
    }
    return NULL;
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *koalaDoctorList)
{
    koalaDoctorList = koalaDoctorList;
    return this;
}

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name)
{
    name = name;
    return this;
}

KoalaDoctor *KoalaDoctorList::getContent()
{
    return _content;
}

KoalaDoctorList *KoalaDoctorList::getNext()
{
    return _next;
}

void KoalaDoctorList::dump()
{
    KoalaDoctorList *actual = this;

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