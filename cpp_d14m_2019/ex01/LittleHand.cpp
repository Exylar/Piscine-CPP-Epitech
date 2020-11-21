/*
** EPITECH PROJECT, 2019
** cpp_d14m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "LittleHand.hpp"

LittleHand::LittleHand() {}

LittleHand::~LittleHand() {}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    int count = unsorted.nbFruits();

    while (unsorted.head() != nullptr || count < 0) {
        if (unsorted.head()->_fruit->getName() == "lemon" && limes.nbFruits() < limes.getMaxFruit())
            lemons.putFruit((unsorted.head()->_fruit));
        if (unsorted.head()->_fruit->getName() == "banana" && limes.nbFruits() < limes.getMaxFruit())
            bananas.putFruit((unsorted.head()->_fruit));;
        if (unsorted.head()->_fruit->getName() == "lime" && limes.nbFruits() < limes.getMaxFruit())
            limes.putFruit((unsorted.head()->_fruit));
        unsorted.putFruit(unsorted.head()->_fruit);
        unsorted.pickFruit();
        count--;
    }
}