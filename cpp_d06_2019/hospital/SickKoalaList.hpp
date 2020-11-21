/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D06_2019_SICKKOALALIST_HPP
#define CPP_D06_2019_SICKKOALALIST_HPP

#include <iostream>
#include "SickKoala.hpp"

class SickKoalaList {
    public:
        SickKoalaList(SickKoala *sickKoala);
        bool isEnd();
        void append(SickKoalaList *sickKoalaList);
        SickKoala *getFromName(std::string name);
        SickKoalaList *remove(SickKoalaList *sickKoalaList);
        SickKoalaList *removeFromName(std::string name);
        SickKoala *getContent();
        SickKoalaList *getNext();
        void dump();
    private:
        SickKoala *_content;
        SickKoalaList *_next;
};

#endif //CPP_D06_2019_SICKKOALALIST_HPP
