/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name) : name(name)
{
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << name  << ": Kreooogg!! I'm cuuuured!" << std::endl;
    name.empty();
}

void SickKoala::poke()
{
    std::cout << "Mr." << name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
    if (str == "Mars") {
        std::cout << "Mr." << name << ": Mars, and it kreogs!" << std::endl;
        return true;
    }
    else if (str == ("Buronzand")) {
        std::cout << "Mr." << name << ": And you'll sleep right away!" << std::endl;
        return true;
    }
    else {
        std::cout << "Mr." << name << ": Goerkreog!" << std::endl;
        return false;
    }
}

void SickKoala::overDrive(std::string str)
{
    while(str.find("Kreog!") != std::string::npos) {
        str.replace(str.find("Kreog!"), 6, "1337!");
    }

    std::cout << "Mr." << name << ": " << str << std::endl;
}

std::string SickKoala::getName()
{
    return name;
}