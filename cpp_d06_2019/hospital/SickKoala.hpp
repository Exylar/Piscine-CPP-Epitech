/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D06_2019_SICKKOALA_H
#define CPP_D06_2019_SICKKOALA_H

#include <iostream>
#include <string>

class SickKoala {
    public:
        SickKoala(std::string name);
        ~SickKoala();
        void poke(void);
        bool takeDrug(std::string str);
        void overDrive(std::string str);
        std::string getName();
    private:
        std::string name;
};

#endif //CPP_D06_2019_SICKKOALA_H
