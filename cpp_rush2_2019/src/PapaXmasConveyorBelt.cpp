/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** PapaXmasConveyorBelt
*/

#include <iostream>
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "PapaXmasConveyorBelt.hpp"

PapaXmasConveyorBelt::PapaXmasConveyorBelt()
{
    obj = nullptr;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
    if (this->obj != nullptr)
        delete this->obj;
}

Object *PapaXmasConveyorBelt::take()
{
    Object *save = this->obj;
    if (this->isEmpty() == true) {
        std::cerr << "ConveyorBelt takeObj: Error: There is ";
        std::cerr << "nothing on the Conveyor Belt" << std::endl;
        return nullptr;
    } else {
        this->obj = nullptr;
        return save;
    }
}

bool PapaXmasConveyorBelt::put(Object *&obj)
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

void PapaXmasConveyorBelt::operator<<(Object *&obj)
{
    if (this->isEmpty() == false) {
        std::cerr << "ConveyorBelt op <<: Error: There is ";
        std::cerr << "already an object on the Conveyor Belt" << std::endl;
    } else {
        this->obj = obj;
        obj = nullptr;
    }
}

bool PapaXmasConveyorBelt::in()
{
    if (this->isEmpty() == false) {
        std::cerr << "ConveyorBelt in: Error: There is ";
        std::cerr << "already an object on the Conveyor Belt" << std::endl;
        return false;
    }
    if (random() % 2 == 0) {
        this->obj = new Box();
    } else {
        this->obj = new GiftPaper();
    }
    if (this->obj == nullptr) {
        std::cerr << "ConveyorBelt in: Error: The creation ";
        std::cerr << "of a new wrap failed." << std::endl;
        return false;
    }
    return true;
}

bool PapaXmasConveyorBelt::out()
{
    if (this->isEmpty() == true) {
        std::cerr << "ConveyorBelt out: Error: There is ";
        std::cerr << "nothing on the Conveyor Belt" << std::endl;
        return false;
    } else {
        delete this->obj;
        this->obj = nullptr;
        return true;
    }
}

bool PapaXmasConveyorBelt::isEmpty() const
{
    if (obj == nullptr)
        return true;
    else
        return false;
}

IConveyorBelt *createConveyorBelt()
{
    IConveyorBelt *newConv = new PapaXmasConveyorBelt();

    return newConv;
}
