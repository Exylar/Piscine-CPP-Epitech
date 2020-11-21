/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** PapaXmasTable
*/

#include "PapaXmasTable.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

PapaXmasTable::PapaXmasTable()
{
    size_t idx = 0;

    for (size_t i = 0; i < MaxSize; i++)
        this->_inventory[i] = nullptr;
    for (size_t i = 0; i < NB_TOY; i++, idx++)
        this->_inventory[idx] = new Teddy();
    for (size_t i = 0; i < NB_BOX; i++, idx++)
        this->_inventory[idx] = new Box();
    for (size_t i = 0; i < NB_GIFT_PAPER; i++, idx++)
        this->_inventory[idx] = new GiftPaper();
}

PapaXmasTable::~PapaXmasTable()
{
    for (size_t i = 0; i < MaxSize; i++) {
        if (this->_inventory[i] != nullptr)
            delete this->_inventory[i];
    }
}

void PapaXmasTable::put(unsigned int idx, Object *&value)
{
    if (idx >= MaxSize || value == nullptr)
        return;
    if (this->_inventory[idx] != nullptr)
        delete this->_inventory[idx];
    this->_inventory[idx] = value;
    value = nullptr;
}

bool PapaXmasTable::operator<<(Object *&newObj)
{
    if (newObj == nullptr)
        return false;
    for (size_t i = 0; i < MaxSize; i++) {
        if (this->_inventory[i] == nullptr) {
            this->_inventory[i] = newObj;
            newObj = nullptr;
            return true;
        }
    }
    return false;
}

Object *PapaXmasTable::operator[](unsigned int idx) const
{
    if (idx >= MaxSize)
        return nullptr;
    return this->_inventory[idx];
}

Object *PapaXmasTable::take(unsigned int idx)
{
    Object *obj;

    if (idx >= MaxSize || this->_inventory[idx] == nullptr)
        return nullptr;
    obj = this->_inventory[idx];
    this->_inventory[idx] = nullptr;
    return obj;
}

PapaXmasTable::operator size_t() const
{
    size_t len = 0;

    for (size_t i = 0; i < MaxSize; i++)
        if (this->_inventory[i] != nullptr) {
            len++;
        }
    return len;
}

std::string **PapaXmasTable::lookAtTheTable() const
{
    std::string **array = new std::string *[MaxSize + 1];

    if (array == nullptr) {
        std::cerr << "lookAtTheTable: error: ";
        std::cerr << "instanciation of the std::string array." << std::endl;
        return nullptr;
    }
    for (size_t i = 0; i < MaxSize; i++) {
        if (this->_inventory[i] != nullptr) {
            array[i] = new std::string(this->_inventory[i]->getTitle());
        } else {
            array[i] = new std::string("");
        }
    }
    array[MaxSize] = nullptr;
    return array;
}

ITable *createTable()
{
    ITable *newTable = new PapaXmasTable();

    return newTable;
}