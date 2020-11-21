/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "iostream"
#include "Cesar.hpp"

Cesar::Cesar() {}

Cesar::~Cesar() {}

void Cesar::reset()
{
    this->_shift = 3;
}

void Cesar::encryptChar(char plainchar)
{
    if (this->_shift == 26)
        this->_shift = 0;

    if (plainchar >= 'a' && plainchar <= 'z') {
        if (((plainchar - 'z') + 26) + this->_shift <= 26)
            std::cout << static_cast<char>(plainchar + this->_shift);
        else
            std::cout << static_cast<char>(plainchar + this->_shift - 26);
    }
    else if (plainchar >= 'A' && plainchar <= 'Z') {
        if (((plainchar - 'Z') + 26) + this->_shift <= 26)
            std::cout << static_cast<char>(plainchar + this->_shift);
        else
            std::cout << static_cast<char>(plainchar + this->_shift - 26);
    }
    else
        std::cout << static_cast<char>(plainchar);
    this->_shift++;
}

void Cesar::decryptChar(char cipherchar)
{
    if (this->_shift == 26)
        this->_shift = 0;

    if (cipherchar >= 'a' && cipherchar <= 'z') {
        if (((cipherchar - 'z') + 26) - this->_shift > 0)
            std::cout << static_cast<char>(cipherchar - this->_shift);
        else
            std::cout << static_cast<char>(cipherchar - this->_shift + 26);
    }
    else if (cipherchar >= 'A' && cipherchar <= 'Z') {
        if (((cipherchar - 'Z') + 26) - this->_shift > 0)
            std::cout << static_cast<char>(cipherchar - this->_shift);
        else
            std::cout << static_cast<char>(cipherchar - this->_shift + 26);
    }
    else
        std::cout << static_cast<char>(cipherchar);
    this->_shift++;
}