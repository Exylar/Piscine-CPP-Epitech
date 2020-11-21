/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string &key) : _key(key) {}

OneTime::~OneTime() {}

void OneTime::reset()
{
    this->_shift = 0;
}

void OneTime::encryptChar(char plainchar)
{
    if (this->_shift == this->_key.length())
        this->_shift = 0;

    if (plainchar >= 'a' && plainchar <= 'z') {
        if (plainchar + std::tolower(this->_key[this->_shift]) - 'a' <= 'z')
            std::cout << static_cast<char>((plainchar + std::tolower(this->_key[this->_shift])) - 'a');
        else
            std::cout << static_cast<char>((plainchar + std::tolower(this->_key[this->_shift])) - 'a' - 26);
    }
    else if (plainchar >= 'A' && plainchar <= 'Z') {
        if (plainchar + std::toupper(this->_key[this->_shift]) - 'A' <= 'Z')
            std::cout << static_cast<char>((plainchar + std::toupper(this->_key[this->_shift])) - 'A');
        else
            std::cout << static_cast<char>((plainchar + std::toupper(this->_key[this->_shift])) - 'A' - 26);
    }
   else
        std::cout << static_cast<char>(plainchar);
    this->_shift++;
}

void OneTime::decryptChar(char cipherchar)
{
    if (this->_shift == this->_key.length())
        this->_shift = 0;

    if (cipherchar >= 'a' && cipherchar <= 'z') {
        if (cipherchar - std::tolower(this->_key[this->_shift]) + 'a' >= 'a')
            std::cout << static_cast<char>((cipherchar - std::tolower(this->_key[this->_shift])) + 'a');
        else
            std::cout << static_cast<char>((cipherchar - std::tolower(this->_key[this->_shift])) + 'a' + 26);
    }
    else if (cipherchar >= 'A' && cipherchar <= 'Z') {
        if (cipherchar - std::toupper(this->_key[this->_shift]) + 'A' >= 'A')
            std::cout << static_cast<char>((cipherchar - std::toupper(this->_key[this->_shift])) + 'A');
        else
            std::cout << static_cast<char>((cipherchar - std::toupper(this->_key[this->_shift])) + 'A' + 26);
    }
    else
        std::cout << static_cast<char>(cipherchar);
    this->_shift++;
}