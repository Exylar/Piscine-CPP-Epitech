/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D06_2019_KOALADOCTORLIST_HPP
#define CPP_D06_2019_KOALADOCTORLIST_HPP

#include <iostream>
#include "KoalaDoctor.hpp"

class KoalaDoctorList {
    public:
        KoalaDoctorList(KoalaDoctor *koalaDoctor);
        bool isEnd();
        void append(KoalaDoctorList *koalaDoctorList);
        KoalaDoctor *getFromName(std::string name);
        KoalaDoctorList *remove(KoalaDoctorList *koalaDoctorList);
        KoalaDoctorList *removeFromName(std::string name);
        KoalaDoctor *getContent();
        KoalaDoctorList *getNext();
        void dump();
    private:
        KoalaDoctor *_content;
        KoalaDoctorList *_next;
};

#endif //CPP_D06_2019_KOALADOCTORLIST_HPP
