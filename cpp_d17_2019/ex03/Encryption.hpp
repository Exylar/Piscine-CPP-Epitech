/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D17_2019_ENCRYPTION_HPP
#define CPP_D17_2019_ENCRYPTION_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include "IEncryptionMethod.hpp"

typedef void(IEncryptionMethod::*methode)(char);

class Encryption {
    public:
        Encryption(IEncryptionMethod &encryptionMethod, methode methodetype);
        ~Encryption();
        void operator()(const char c);

        static void encryptString(IEncryptionMethod &encryptionMethod, const std::string &toEncrypt);
        static void decryptString(IEncryptionMethod &encryptionMethod, const std::string &toDecrypt);
    private:
        IEncryptionMethod *_method;
        methode _type;

};

#endif //CPP_D17_2019_ENCRYPTION_HPP
