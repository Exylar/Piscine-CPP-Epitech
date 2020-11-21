/*
** EPITECH PROJECT, 2019
** cpp_d07a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Parts.hpp"

Arms::Arms(std::string serial, bool functional) : _serial(serial), _functional(functional) {}

bool Arms::isFunction() const
{
    return (_functional);
}

std::string Arms::serial() const
{
    return _serial;
}

void Arms::information() const
{
    std::cout << "[Parts] Arms "<< _serial << " status :";
    if (_functional)
        std::cout << " OK" << std::endl;
    else
        std::cout << " KO" << std::endl;
}

Legs::Legs(std::string serial, bool functional) : _serial(serial), _functional(functional) {}

bool Legs::isFunction() const
{
    return (_functional);
}

std::string Legs::serial() const
{
    return _serial;
}

void Legs::information() const
{
    std::cout << "[Parts] Legs "<< _serial << " status :";
    if (_functional)
        std::cout << " OK" << std::endl;
    else
        std::cout << " KO" << std::endl;
}

Head::Head(std::string serial, bool functional) : _serial(serial), _functional(functional) {}

bool Head::isFunction() const
{
    return (_functional);
}

std::string Head::serial() const
{
    return _serial;
}

void Head::information() const
{
    std::cout << "[Parts] Head "<< _serial << " status :";
    if (_functional)
        std::cout << " OK" << std::endl;
    else
        std::cout << " KO" << std::endl;
}