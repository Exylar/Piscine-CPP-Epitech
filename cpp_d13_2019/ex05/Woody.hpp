/*
** EPITECH PROJECT, 2019
** cpp_d13_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D13_2019_WOODY_HPP
#define CPP_D13_2019_WOODY_HPP

#include "Toy.hpp"

class Woody : public Toy{
    public:
        Woody(const std::string &name);
        Woody(const std::string &name, const std::string filename);
        virtual ~Woody();
        void speak(const std::string statement);
        bool speak_es(std::string statement);
};

#endif //CPP_D13_2019_WOODY_HPP
