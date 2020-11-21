/*
** EPITECH PROJECT, 2019
** cpp_d13_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Picture.hpp"

Picture::Picture() : _data("") {}

Picture::Picture(const std::string &file) : _data("")
{
    getPictureFromFile(file);
}

Picture::~Picture() {}

bool Picture::getPictureFromFile(const std::string &file)
{
    struct stat buffer;

    if (stat (file.c_str(), &buffer) == 0) {
        std::ifstream my_file(file);
        std::stringstream buffer;
        buffer << my_file.rdbuf();
        this->_data = buffer.str();
        return true;
    }
    this->_data = "ERROR";
    return false;
}
