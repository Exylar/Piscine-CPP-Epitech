/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Hand
*/

#ifndef HAND_HPP_
#define HAND_HPP_

#include "Object.hpp"

class Hand
{
    public:
        Hand();
        ~Hand();

        Object *getObj();
        void setObj(Object *);
        bool isEmpty() const;

        Object *operator*();

    private:
        Object *_obj;
};

#endif /* !HAND_HPP_ */
