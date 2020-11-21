/*
** EPITECH PROJECT, 2019
** cpp_d13_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D13_2019_TOYSTORY_HPP
#define CPP_D13_2019_TOYSTORY_HPP

#include <iostream>
#include <fstream>
#include "Toy.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"
#include "Picture.hpp"

class ToyStory {
    public:
        static void tellMeAStory(const std::string filename, Toy &toy1, bool (Toy::*func)(std::string), Toy &toy2, bool (Toy::*func2)(std::string));
};

#endif //CPP_D13_2019_TOYSTORY_HPP
