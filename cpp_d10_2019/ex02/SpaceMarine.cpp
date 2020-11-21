/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "SpaceMarine.hpp"

SpaceMarine::SpaceMarine()
{
    std::cout << "Tactical Marine ready for battle" << std::endl;
}

SpaceMarine::~SpaceMarine()
{
    std::cout << "Aaargh..." << std::endl;
}

SpaceMarine* SpaceMarine::clone()
{
    return new SpaceMarine(*this);
}

void SpaceMarine::battleCry() const
{
    std::cout << "For the holy PLOT!" << std::endl;
}

void SpaceMarine::rangedAttack() const
{
    std::cout << "* attacks with bolter *" << std::endl;
}

void SpaceMarine::melleAttack() const
{
    std::cout << "* attacks with chainsword *" << std::endl;
}