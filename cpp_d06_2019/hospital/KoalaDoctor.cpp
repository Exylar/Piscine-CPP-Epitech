/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "KoalaDoctor.hpp"
#include "SickKoala.hpp"

KoalaDoctor::KoalaDoctor(std::string name) : name(name)
{
    std::cout << "Dr." << name  << ": I'm Dr." << name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
    name.empty();
}

void KoalaDoctor::diagnose(SickKoala *sickKoala)
{
    std::ofstream myfile;
    int aleatoire = 0;
    std::string filename = sickKoala[0].getName() + ".report";

    std::cout << "Dr." << name  << ": So what's goerking you Mr." << sickKoala[0].getName() << "?" << std::endl;
    sickKoala[0].poke();
    aleatoire = rand()%5;
    myfile.open(filename);
    if (aleatoire == 1)
        myfile << "Mars";
    else if (aleatoire == 2)
        myfile << "Buronzand";
    else if (aleatoire == 3)
        myfile << "Viagra";
    else if (aleatoire == 4)
        myfile << "Extasy";
    else if (aleatoire == 5)
        myfile << "Eucalyptus lead";
    myfile.close();
}

void KoalaDoctor::timeCheck()
{
    if (status == 0) {
        status = 1;
        std::cout << "Dr." << name << ": Time to get to work!" << std::endl;
    } else {
        status = 0;
        std::cout << "Dr." << name << ": Time to go home to my eucalyptus forest!" << std::endl;
    }
}

std::string KoalaDoctor::getName()
{
    return name;
}