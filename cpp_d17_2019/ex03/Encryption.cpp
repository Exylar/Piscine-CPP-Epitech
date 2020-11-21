/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Encryption.hpp"

Encryption::Encryption(IEncryptionMethod &encryptionMethod,  methode methodetype) : _method(&encryptionMethod), _type(methodetype) {}

Encryption::~Encryption() {}

void Encryption::operator()(const char c)
{
    (_method->*_type)(c);
}

void Encryption::encryptString(IEncryptionMethod &encryptionMethod, const std::string &toEncrypt)
{
    encryptionMethod.reset();
    std::for_each(toEncrypt.begin(), toEncrypt.end(), Encryption(encryptionMethod, &IEncryptionMethod::encryptChar));
    std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod &decryptionMethod, const std::string &toDecrypt)
{
    decryptionMethod.reset();
    std::for_each(toDecrypt.begin(), toDecrypt.end(), Encryption(decryptionMethod, &IEncryptionMethod::decryptChar));
    std::cout << std::endl;
}