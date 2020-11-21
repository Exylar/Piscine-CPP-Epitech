/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TableRand
*/

#include <memory>
#include "TableRand.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

TableRand::TableRand()
{
    static const std::unique_ptr<Object> teddy(new Teddy());
    static const std::unique_ptr<Object> pony(new LittlePony());
    static const std::unique_ptr<Object> box(new Box());
    static const std::unique_ptr<Object> paper(new GiftPaper());
    static const Object *objs[4] =
{teddy.get(), pony.get(), box.get(), paper.get()};
    size_t nbToGenerate = random() % 10;

    for (size_t i = 0; i < MaxSize; i++) {
        this->_inventory[i] = nullptr;
    }
    for (size_t i = 0; i < nbToGenerate; i++) {
        this->_inventory[i] = objs[random() % 4]->clone();
        if (this->_inventory[i] == nullptr) {
            std::cerr << "tableRand ctor: error: instanciation of a random ";
            std::cerr << "object faild at index: " << i << "." << std::endl;
        }
    }
}

TableRand::~TableRand()
{
    for (size_t i = 0; i < MaxSize; i++) {
        if (this->_inventory[i] != nullptr)
            delete this->_inventory[i];
    }
}

void TableRand::put(unsigned int idx, Object *&value)
{
    if (idx >= MaxSize || value == nullptr)
        return;
    if (this->_inventory[idx] != nullptr)
        delete this->_inventory[idx];
    this->_inventory[idx] = value;
    value = nullptr;
}

bool TableRand::operator<<(Object *&newObj)
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

Object *TableRand::operator[](unsigned int idx) const
{
    if (idx >= MaxSize)
        return nullptr;
    return this->_inventory[idx];
}

Object *TableRand::take(unsigned int idx)
{
    Object *obj;

    if (idx >= MaxSize || this->_inventory[idx] == nullptr)
        return nullptr;
    obj = this->_inventory[idx];
    this->_inventory[idx] = nullptr;
    return obj;
}

TableRand::operator size_t() const
{
    size_t len = 0;

    for (size_t i = 0; i < MaxSize; i++) {
        if (this->_inventory[i] != nullptr) {
            len++;
        }
    }
    return len;
}

std::string **TableRand::lookAtTheTable() const
{
    std::string **array = new std::string *[MaxSize + 1];

    if (array == nullptr) {
        std::cerr << "lookAtTheTable: error: instanciation ";
        std::cerr << "of the std::string array." << std::endl;
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