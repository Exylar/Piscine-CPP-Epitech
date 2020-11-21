/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D06_2019_KOALADOCTOR_HPP
#define CPP_D06_2019_KOALADOCTOR_HPP

#include <iostream>
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

class KoalaDoctor {
public:
    KoalaDoctor(std::string name);
    ~KoalaDoctor();
    void diagnose(SickKoala *sickKoala);
    void timeCheck();
    std::string getName();
private:
    std::string name;
    int status = 0;
};

#endif //CPP_D06_2019_KOALADOCTOR_HPP
