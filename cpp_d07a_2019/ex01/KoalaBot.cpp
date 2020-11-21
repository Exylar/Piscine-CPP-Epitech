/*
** EPITECH PROJECT, 2019
** cpp_d07a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial) : _serial(serial) {}

void KoalaBot::setParts(Head &head)
{
    _head = &head;
}

void KoalaBot::setParts(Legs &legs)
{
    _legs = &legs;
}

void KoalaBot::setParts(Arms &arms)
{
    _arms = &arms;
}

void KoalaBot::swapParts(Head &head)
{
    Head *buff = _head;

    _head = &head;
    head = *buff;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs *buff = _legs;

    _legs = &legs;
    legs = *buff;
}

void KoalaBot::swapParts(Arms &arms)
{
    Arms *buff = _arms;

    _arms = &arms;
    arms = *buff;
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    if (_arms) {
        std::cout << "\t";
        _arms->information();
    }
    if (_legs) {
        std::cout << "\t";
        _legs->information();
    }
    if (_head) {
        std::cout << "\t";
        _head->information();
    }
}

bool KoalaBot::status() const
{
    return (_arms->isFunction() && _legs->isFunction() && _head->isFunction());
}