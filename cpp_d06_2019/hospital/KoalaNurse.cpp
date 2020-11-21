/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

KoalaNurse::KoalaNurse(int ID) : ID(ID), status(0)
{
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << ID  << ": Finaly some rest!" << std::endl;
    ID = 0;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *sickKoala)
{
    sickKoala[0].takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::string drug;
    std::ifstream fs;
    std::stringstream buffer;
    int pos = 0;

    fs.open(filename);
    if (fs.is_open()) {
        buffer << fs.rdbuf();
        std::string drug = buffer.str();
        fs.close();
        pos = filename.find(".");
        std::cout << "Nurse " << ID << ": Kreog! Mr." << filename.substr(0, pos) << " needs a " << drug.substr(0, drug.size() - 1) << "!" << std::endl;
        return drug;
    } else
        return "";
}

void KoalaNurse::timeCheck()
{
    if (status == 0) {
        status = 1;
        std::cout << "Nurse " << ID << ": Time to get to work!" << std::endl;
    } else {
        status = 0;
        std::cout << "Nurse " << ID << ": Time to go home to my eucalyptus forest!" << std::endl;
    }
}

int KoalaNurse::getID()
{
    return ID;
}