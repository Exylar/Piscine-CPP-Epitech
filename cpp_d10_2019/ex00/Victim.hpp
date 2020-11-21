/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D10_2019_VICTIM_H
#define CPP_D10_2019_VICTIM_H

#include <iostream>

class Victim {
    public:
        Victim(std::string name);
        ~Victim();
        void getPolymorphed() const;
        std::string getName() const;
        void setName(std::string name);
    protected:
        std::string _name;
};

std::ostream &operator<<(std::ostream &out, const Victim &victim);

#endif //CPP_D10_2019_VICTIM_H
