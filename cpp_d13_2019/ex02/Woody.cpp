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