/*
** EPITECH PROJECT, 2019
** cpp_d14m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D14M_2019_LITTLEHAND_HPP
#define CPP_D14M_2019_LITTLEHAND_HPP

#include "FruitBox.hpp"
#include "FruitNode.hpp"

class LittleHand {
    public:
        LittleHand();
        ~LittleHand();
        void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
};

#endif //CPP_D14M_2019_LITTLEHAND_HPP
