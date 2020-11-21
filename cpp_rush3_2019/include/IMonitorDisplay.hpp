/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_RUSH3_2019_IMONITORDISPLAY_HPP
#define CPP_RUSH3_2019_IMONITORDISPLAY_HPP

#include <iostream>

class IMonitorDisplay {
    public:
        virtual ~IMonitorDisplay() {};
        virtual bool isOpen() = 0;
        virtual void Update() = 0;
        virtual void DisplayTitle(std::string str) = 0;
        virtual void DisplaySubTitle(std::string str) = 0;
        virtual void DisplayText(std::string str) = 0;
        virtual void DisplayBar(std::string name, int value) = 0;
        virtual void DisplayGraph(std::string name, int value) = 0;
        virtual void DisplaySeparator() = 0;
        virtual bool *GetModules() = 0;
};

#endif //CPP_RUSH3_2019_IMONITORDISPLAY_HPP