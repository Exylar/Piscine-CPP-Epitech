/*
** EPITECH PROJECT, 2019
** cpp_d13_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name) : Toy(Toy::BUZZ, name, "buzz.txt") {}

Buzz::Buzz(const std::string &name, const std::string filename) : Toy(Toy::BUZZ, name, filename) {}

Buzz::~Buzz() {}

void Buzz::speak(const std::string statement)
{
    std::cout << "BUZZ: " << this->_name << " \"" << statement << "\"" << std::endl;
}