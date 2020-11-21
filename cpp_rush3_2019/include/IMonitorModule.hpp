/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_RUSH3_2019_IMONITORMODULE_HPP
#define CPP_RUSH3_2019_IMONITORMODULE_HPP

#include <string>
#include "IMonitorDisplay.hpp"

class IMonitorModule {
    public:
        virtual ~IMonitorModule() {};
        virtual void Display(IMonitorDisplay *iMonitorDisplay) const = 0;
        virtual std::string const &GetName() const = 0;
        virtual void Update() = 0;
};

#endif //CPP_RUSH3_2019_IMONITORMODULE_HPP
