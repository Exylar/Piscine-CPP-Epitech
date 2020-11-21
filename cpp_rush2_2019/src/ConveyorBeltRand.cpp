/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ConveyorBeltRand
*/

#include <iostream>
#include <fstream>
#include "ConveyorBeltRand.hpp"
#include "Teddy.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "LittlePony.hpp"

int ConveyorBeltRand::i = 1;

ConveyorBeltRand::ConveyorBeltRand()
{
    this->obj = nullptr;
}

ConveyorBeltRand::~ConveyorBeltRand()
{
    if (this->obj != nullptr)
        delete this->obj;
}

Object *ConveyorBeltRand::take()
{
    Object *save = this->obj;
    if (this->isEmpty() == true) {
        std::cerr << "ConveyorBelt takeObj: Error: ";
        std::cerr << "There is nothing on the Conveyor Belt" << std::endl;
        return nullptr;
    } else {
        this->obj = nullptr;
        return save;
    }
}

bool ConveyorBeltRand::put(Object *&obj)
{
    if (this->isEmpty() == false) {
        std::cerr << "ConveyorBelt put: Error: There is ";
        std::cerr << "already an object on the Conveyor Belt" << std::endl;
        return false;
    } else {
        this->obj = obj;
        obj = nullptr;
        return true;
    }
}

void ConveyorBeltRand::operator<<(Object *&obj)
{
    if (this->isEmpty() == false) {
        std::cerr << "ConveyorBelt putObj: Error: There is ";
        std::cerr << "already an object on the Conveyor Belt" << std::endl;
    } else {
        this->obj = obj;
        obj = nullptr;
    }
}

bool ConveyorBeltRand::in()
{
    int val = random() % 4;

    if (this->isEmpty() == false) {
        std::cerr << "ConveyorBelt in: Error: There is ";
        std::cerr << "already an object on the Conveyor Belt" << std::endl;
        return false;
    }
    if (val == 0)
        this->obj = new Box();
    if (val == 1)
        this->obj = new GiftPaper();
    if (val == 2)
        this->obj = new LittlePony();
    if (val == 3)
        this->obj = new Teddy();
    if (this->obj == nullptr) {
        std::cerr << "ConveyorBelt in: Error: The instanciation ";
        std::cerr << "of a random object failed." << std::endl;
        return false;
    }
    return true;
}

bool ConveyorBeltRand::writeFile(Object *obj)
{
    std::string str = this->parser.SerializeString(obj);
    std::ofstream ofs;

    ofs.open("gift" + std::to_string(this->i) +
".xml", std::ios::out | std::ios::trunc);
    this->i++;
    if (ofs.is_open() == false) {
        std::cerr << "Can't create file" << std::endl;
        return false;
    }
    ofs << str;
    ofs.close();
    return true;
}

bool ConveyorBeltRand::out()
{
    if (this->isEmpty() == true) {
        std::cerr << "ConveyorBelt out: Error: There is ";
        std::cerr << "nothing on the Conveyor Belt" << std::endl;
        return false;
    } else {
        if (writeFile(this->obj) == true) {
            this->obj = nullptr;
            return true;
        } else {
            return false;
        }
    }
}

bool ConveyorBeltRand::isEmpty() const
{
    if (obj == nullptr)
        return true;
    else
        return false;
}