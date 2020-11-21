/*
** EPITECH PROJECT, 2019
** cpp_d07a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D07A_2019_KOALABOT_HPP
#define CPP_D07A_2019_KOALABOT_HPP

#include <iostream>
#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(std::string serial = "Bob-01");
        void setParts(Head &head);
        void setParts(Legs &legs);
        void setParts(Arms &arms);
        void swapParts(Head &head);
        void swapParts(Legs &legs);
        void swapParts(Arms &arms);
        void informations() const;
        bool status() const;
    private:
        Arms *_arms = NULL;
        Legs *_legs = NULL;
        Head *_head = NULL;
        std::string _serial;
};

#endif //CPP_D07A_2019_KOALABOT_HPP
