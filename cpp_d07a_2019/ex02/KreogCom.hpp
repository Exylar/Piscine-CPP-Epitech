/*
** EPITECH PROJECT, 2019
** cpp_d07a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D07A_2019_KREOGCOM_HPP
#define CPP_D07A_2019_KREOGCOM_HPP

#include <iostream>

class KreogCom {
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();
        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom() const;
        void ping() const;
        void locateSquad() const;
    private:
        int _x;
        int _y;
        const int _m_serial;
        KreogCom *_next = NULL;
};

#endif //CPP_D07A_2019_KREOGCOM_HPP
