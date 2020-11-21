/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D17_2019_CESAR_HPP
#define CPP_D17_2019_CESAR_HPP

#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod{
    public:
        Cesar();
        ~Cesar() override ;
        void encryptChar(char plainchar) override ;
        void decryptChar(char cipherchar) override;
        void reset() override ;
    private:
        int _shift = 3;
};

#endif //CPP_D17_2019_CESAR_HPP
