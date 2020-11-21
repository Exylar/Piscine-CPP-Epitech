/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D17_2019_ONETIME_HPP
#define CPP_D17_2019_ONETIME_HPP

#include <iostream>
#include <string>
#include "IEncryptionMethod.hpp"

class OneTime : public IEncryptionMethod{
    public:
        OneTime(const std::string &key);
        ~OneTime() override ;
        void encryptChar(char plainchar) override ;
        void decryptChar(char cipherchar) override;
        void reset() override ;
    private:
        size_t _shift = 0;
        const std::string _key;
};

#endif //CPP_D17_2019_ONETIME_HPP
