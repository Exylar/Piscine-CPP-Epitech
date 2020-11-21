/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Santa
*/

#ifndef SANTA_HPP_
#define SANTA_HPP_

#include "Object.hpp"
#include "Wrap.hpp"

class Santa {
    public:
       Santa();
       ~Santa();
        bool checkGift(Object *) const;
};

#endif /* !SANTA_HPP_ */
