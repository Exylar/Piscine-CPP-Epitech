/*
** EPITECH PROJECT, 2019
** cpp_d07a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D07A_2019_PARTS_HPP
#define CPP_D07A_2019_PARTS_HPP

#include <iostream>
#include "Parts.hpp"

class Arms {
    public:
        Arms(std::string serial = "A-01", bool functional = true);
        bool isFunction() const;
        std::string serial() const;
        void information() const;
    private:
        std::string _serial;
        bool _functional;
};

class Legs {
    public:
        Legs(std::string serial = "L-01", bool functional = true);
        bool isFunction() const;
        std::string serial() const;
        void information() const;
    private:
        std::string _serial;
        bool _functional;
};

class Head {
    public:
        Head(std::string serial = "H-01", bool functional = true);
        bool isFunction() const;
        std::string serial() const;
        void information() const;
    private:
        std::string _serial;
        bool _functional;
};

#endif //CPP_D07A_2019_PARTS_HPP
