/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D06_2019_KOALANURSELIST_HPP
#define CPP_D06_2019_KOALANURSELIST_HPP

#include <iostream>
#include "KoalaNurse.hpp"

class KoalaNurseList {
    public:
    KoalaNurseList(KoalaNurse *koalaNurse);
        bool isEnd();
        void append(KoalaNurseList *koalaNurseList);
        KoalaNurse *getFromName(int ID);
        KoalaNurseList *remove(KoalaNurseList *koalaNurseList);
        KoalaNurseList *removeFromName(int ID);
        KoalaNurse *getContent();
        KoalaNurseList *getNext();
        void dump();
    private:
    KoalaNurse *_content;
    KoalaNurseList *_next;
};


#endif //CPP_D06_2019_KOALANURSELIST_HPP
