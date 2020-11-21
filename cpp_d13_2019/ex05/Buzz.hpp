/*
** EPITECH PROJECT, 2019
** cpp_d13_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D13_2019_BUZZ_HPP
#define CPP_D13_2019_BUZZ_HPP

#include "Toy.hpp"
#include <iostream>

class Buzz : public Toy {
    public:
        Buzz(const std::string &name);
        Buzz(const std::string &name, const std::string filename);
        virtual ~Buzz();
        void speak(const std::string statement);
        bool speak_es(const std::string statement);
};

#endif //CPP_D13_2019_BUZZ_HPP
