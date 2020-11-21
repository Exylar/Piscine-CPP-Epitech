/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_RUSH3_2019_CORE_HPP
#define CPP_RUSH3_2019_CORE_HPP

#include <vector>
#include "IMonitorModule.hpp"

class Core {
    public:
        Core();
        ~Core();
    private:
        std::vector<IMonitorModule> _listModule;
};

#endif //CPP_RUSH3_2019_CORE_HPP
