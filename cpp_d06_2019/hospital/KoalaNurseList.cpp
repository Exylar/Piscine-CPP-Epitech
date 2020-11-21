/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *koalaNurse) {
    _content = koalaNurse;
    _next = NULL;
}

bool KoalaNurseList::isEnd()
{
    if (_next == NULL)
        return false;
    return true;
}

void KoalaNurseList::append(KoalaNurseList *koalaNurseList)
{
    if (_next == NULL)
        _next = koalaNurseList;
    else
        getNext()->append(koalaNurseList);

}

KoalaNurse *KoalaNurseList::getFromName(int ID)
{
    if (_content->getID() == ID)
        return _content;
    else if (_next != NULL) {
        return getNext()->getFromName(ID);
    }
    return NULL;
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *koalaNurseList)
{
    koalaNurseList = koalaNurseList;
    return this;
}

KoalaNurseList *KoalaNurseList::removeFromName(int ID)
{
    ID = ID;
    return this;
}

KoalaNurse *KoalaNurseList::getContent()
{
    return _content;
}

KoalaNurseList *KoalaNurseList::getNext()
{
    return _next;
}

void KoalaNurseList::dump()
{
    KoalaNurseList *actual = this;

    std::cout << "Patients: ";
    while (actual->_next) {
        if (actual->getContent()->getID() != 0)
            std::cout << actual->getContent()->getID() << ", ";
        else
            std::cout << "nullptr, ";
        actual = actual->getNext();
    }
    std::cout << actual->getContent()->getID() << "." << std::endl;
}