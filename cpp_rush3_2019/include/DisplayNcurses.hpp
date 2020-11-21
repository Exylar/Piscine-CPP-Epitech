/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_RUSH3_2019_NCURSES_HPP
#define CPP_RUSH3_2019_NCURSES_HPP


#include <string>
#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
#include "IMonitorDisplay.hpp"

void terminal_start();
void terminal_stop(int sig);
void resizehandler(int sig);
void finish(int sig);
bool khbit(void);

class DisplayNcurses : public IMonitorDisplay {
    public:
        DisplayNcurses();
        ~DisplayNcurses();
        bool isOpen();
        void DisplayTitle(std::string str);
        void DisplaySubTitle(std::string str);
        void DisplayText(std::string str);
        void DisplayBar(std::string name, int value);
        void DisplayGraph(std::string name, int value);
        void DisplaySeparator();
        void Update();
        bool *GetModules();
    private:
        int _x = 1;
        int _y = 5;
};

#endif //CPP_RUSH3_2019_NCURSES_HPP
