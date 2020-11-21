/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D10_2019_PEON_H
#define CPP_D10_2019_PEON_H

#include "Victim.hpp"

class Peon : public Victim {
    public:
        Peon(std::string name);
        ~Peon();
        void getPolymorphed() const;
    private:
};

#endif //CPP_D10_2019_PEON_H
