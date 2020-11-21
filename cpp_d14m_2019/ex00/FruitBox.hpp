/*
** EPITECH PROJECT, 2019
** cpp_d14m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D14M_2019_FRUITBOX_HPP
#define CPP_D14M_2019_FRUITBOX_HPP

#include <iostream>
#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int size);
        virtual ~FruitBox();

        int nbFruits();
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head();
    private:
        int _maxFruit;
        FruitNode *_next;
};

#endif //CPP_D14M_2019_FRUITBOX_HPP
