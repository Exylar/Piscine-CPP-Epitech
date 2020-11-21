/*
** EPITECH PROJECT, 2019
** cpp_d07a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) : _x(x), _y(y), _m_serial(serial) {
    std::cout << "KreogCom " << _m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom() {
    std::cout << "KreogCom " << _m_serial << " shutting down" << std::endl;
    _x = 0;
    _y = 0;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *new_elem = new KreogCom(x, y, serial);
    if (_next == NULL)
        _next = new_elem;
    else {
        new_elem->_next = _next;
        _next = new_elem;
    }
}

void KreogCom::removeCom()
{
    KreogCom *element;

    if (_next->_next != NULL) {
        element = _next;
        _next = _next->_next;
    } else {
        element = _next;
        _next = NULL;
    }
    delete element;
}

KreogCom *KreogCom::getCom() const
{
    return _next;
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << _m_serial << " currently at " << _x << " " << _y << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom *actual = this;

    while (actual->_next != NULL) {
        actual->ping();
        actual = actual->_next;
    }
    actual->ping();
}