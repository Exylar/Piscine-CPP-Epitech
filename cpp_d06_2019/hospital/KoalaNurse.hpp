/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D06_2019_KOALANURSE_HPP
#define CPP_D06_2019_KOALANURSE_HPP

#include "SickKoala.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class KoalaNurse {
    public:
        KoalaNurse(int ID);
        ~KoalaNurse();
        void giveDrug(std::string drug, SickKoala *sickKoala);
        std::string readReport(std::string filename);
        void timeCheck();
        int getID();
    private:
        int ID;
        int status = 0;
};

#endif //CPP_D06_2019_KOALANURSE_HPP
