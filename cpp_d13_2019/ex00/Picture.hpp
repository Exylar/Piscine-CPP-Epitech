/*
** EPITECH PROJECT, 2019
** cpp_d13_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D13_2019_PICTURE_HPP
#define CPP_D13_2019_PICTURE_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <sys/stat.h>

class Picture {
    public:
        Picture();
        Picture(const std::string &file);
       ~Picture();
       bool getPictureFromFile(const std::string &file);
       std::string _data;
};

#endif //CPP_D13_2019_PICTURE_HPP
