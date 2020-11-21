/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D10_2019_SORCERER_H
#define CPP_D10_2019_SORCERER_H

#include "Victim.hpp"
#include "Peon.hpp"
#include <iostream>

class Sorcerer {
    public:
        Sorcerer(std::string name, std::string title);
        ~Sorcerer();
        virtual void polymorph(const Victim &victim) const;
        virtual void polymorph(const Peon &peon) const;
        std::string getName() const;
        std::string getTitle() const;
        void setName(std::string name);
        void setTitle(std::string title);
    private:
        std::string _name;
        std::string _title;
};

std::ostream &operator<<(std::ostream &out, const Sorcerer &sorcerer);

#endif //CPP_D10_2019_SORCERER_H
