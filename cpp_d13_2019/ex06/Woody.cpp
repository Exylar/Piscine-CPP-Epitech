/*
** EPITECH PROJECT, 2019
** cpp_d13_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name) : Toy(Toy::WOODY, name, "woody.txt") {}

Woody::Woody(const std::string &name, const std::string filename) : Toy(Toy::WOODY, name, filename) {}

Woody::~Woody() {}

bool Woody::speak(const std::string statement)
{
    std::cout << "WOODY: " << this->_name << " \"" << statement << "\"" << std::endl;
    return true;
}

bool Woody::speak_es(const std::string statement)
{
    (void)statement;
    this->_error.type = Toy::Error::SPEAK;
    return false;
}