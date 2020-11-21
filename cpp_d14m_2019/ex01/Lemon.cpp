/*
** EPITECH PROJECT, 2019
** cpp_d14m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Lemon.hpp"

Lemon::Lemon() : Fruit("lemon", 3) {}

Lemon::Lemon(const std::string &name, int vitamins) : Fruit(name, vitamins) {}

Lemon::~Lemon() {}