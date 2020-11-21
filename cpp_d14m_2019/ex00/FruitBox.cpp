/*
** EPITECH PROJECT, 2019
** cpp_d14m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size) : _maxFruit(size), _next(nullptr) {
}

FruitBox::~FruitBox()
{
    FruitNode *save_prev = this->_next;
    FruitNode *save = this->_next;

    while (save) {
        if (save->_next) {
            save_prev = save;
            save = save->_next;
            delete save_prev;
        }
        else {
            delete save;
            break;
        }
    }
}

int FruitBox::nbFruits()
{
    int count = 0;
    FruitNode *save = this->_next;

    while (save) {
        count++;
        if (save->_next)
            save = save->_next;

        else
            break;
    }
    return count;
}

bool FruitBox::putFruit(Fruit *f)
{
    if (!f || this->nbFruits() > this->_maxFruit)
        return false;
    if (this->_next == nullptr) {
        FruitNode *fruit = new FruitNode;
        Fruit &new_fruit = *f;
        this->_next = fruit;
        this->_next->_fruit = &new_fruit;
        return true;
    }
    FruitNode *save = this->_next;
    while (save) {
        if (save->_fruit == f)
            return false;
        if (save->_next)
            save = save->_next;
        else
            break;
    }
    FruitNode *fruit = new FruitNode;
    Fruit &new_fruit = *f;
    save->_next = fruit;
    save->_next->_fruit = &new_fruit;
    return true;
}

Fruit* FruitBox::pickFruit()
{
    if (this->_next->_fruit) {
        if (this->_next->_next)
            this->_next = this->_next->_next;
        else
            this->_next = nullptr;
        return this->_next->_fruit;
    }
    return nullptr;
}

FruitNode* FruitBox::head()
{
    if (this->_next)
        return this->_next;
    return nullptr;
}