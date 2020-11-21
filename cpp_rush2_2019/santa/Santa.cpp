/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Santa
*/

#include "Santa.hpp"

Santa::Santa()
{
}

Santa::~Santa()
{
}

bool Santa::checkGift(Object *toCheck) const
{
    Object *box;
    Object *toy;

    std::cout << "* Santa is checking the received gift *" << std::endl;
    if (toCheck == nullptr || toCheck->canWrap() == false) {
        std::cerr << "Santa: There is something wrong with that gift!" << std::endl;
        return false;
    }
    ((Wrap *)toCheck)->openMe();
    box = ((Wrap *)toCheck)->getContent();
    if (box == nullptr || box->canWrap() == false) {
        std::cerr << "Santa: There is something wrong with that gift!" << std::endl;
        return false;
    }
    ((Wrap *)box)->openMe();
    toy = ((Wrap *)box)->getContent();
    if (toy == nullptr || toy->canWrap() == true) {
        std::cerr << "Santa: There is something wrong with that gift!" << std::endl;
        return false;
    }
    toy->isTaken();
    ((Wrap *)box)->wrapMeThat(toy);
    ((Wrap *)box)->closeMe();
    ((Wrap *)toCheck)->wrapMeThat(box);
    ((Wrap *)toCheck)->closeMe();
    std::cout << "* Santa is putting the gift in the sleigh *" << std::endl;
    return true;
}