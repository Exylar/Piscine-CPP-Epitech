/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "DisplayNcurses.hpp"

#include <iostream>
#include <sys/select.h>
#include <chrono>
#include <thread>

bool khbit(void)
{
    struct timeval tv;
    fd_set read_fd;

    tv.tv_sec=0;
    tv.tv_usec=0;

    FD_ZERO(&read_fd);
    FD_SET(0,&read_fd);
    if(select(1, &read_fd,NULL, NULL, &tv) == -1)
        return 0;
    if(FD_ISSET(0,&read_fd))
        return 1;
    return 0;
}

void terminal_start() {

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    refresh();
}

void terminal_stop(int sig)
{
    sig = sig;
    endwin();
}

void finish(int sig)
{
    (void)sig;
    endwin();
    exit (0);
}

void resize(int sig)
{
    (void)sig;
    terminal_stop(sig);
    terminal_start();
}

DisplayNcurses::DisplayNcurses()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    signal(SIGINT, finish);
    signal(SIGWINCH, resize);
    if (!has_colors())
        printw("No colors");
    start_color();
    refresh();
}

DisplayNcurses::~DisplayNcurses() {terminal_stop(0);}

void DisplayNcurses::DisplayBar(std::string name, int value)
{
    if (value > 100)
        value = 100;
    init_pair(1 ,COLOR_GREEN, COLOR_BLACK);
    init_pair(2 ,COLOR_YELLOW, COLOR_BLACK);
    init_pair(3 ,COLOR_RED, COLOR_BLACK);

    mvprintw(this->_x, this->_y, name.c_str());
    mvprintw(this->_x + 1, this->_y,"[");
    for (int i = 0; i < value / 2; i++) {
        if (i < 20)
            attron(COLOR_PAIR(1));
        else if (i >= 20 && i < 35)
            attron(COLOR_PAIR(2));
        else
            attron(COLOR_PAIR(3));
        mvprintw(this->_x + 1, this->_y + 1 + i, "|");
    }
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    for (int i = 0; i < 50 - (value / 2); i++)
        printw(" ");
    printw("]");
    printw((std::to_string(value)).c_str());
    printw(" %\n");
    this->_x = this->_x + 3;
}

void DisplayNcurses::DisplaySeparator()
{
    int maxWidth = 0;
    int maxHeight = 0;

    (void)maxHeight;
    getmaxyx(stdscr, maxHeight, maxWidth);
    for (int i = 0; i < maxWidth; i++)
        mvprintw(this->_x, i, "-");
    this->_x = this->_x + 1;
}

void DisplayNcurses::DisplayText(std::string str)
{
    mvprintw(this->_x, this->_y, str.c_str());
    this->_x += 1;
}

void DisplayNcurses::DisplaySubTitle(std::string str)
{
    mvprintw(this->_x, this->_y * 2, str.c_str());
    this->_x += 1;
}

void DisplayNcurses::DisplayTitle(std::string str)
{
    mvprintw(this->_x, this->_y, str.c_str());
    this->_x += 1;
}

void DisplayNcurses::DisplayGraph(std::string name, int value)
{
    DisplayBar(name, value);
}

bool DisplayNcurses::isOpen()
{
    if (!khbit())
        return (true);
    if (getch() == 27) {
        endwin();
        return false;
    }
    return true;
}

void DisplayNcurses::Update()
{
    refresh();
    this->_x = 1;
    this->_y = 5;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

bool *DisplayNcurses::GetModules()
{
    static bool activate[7] = {true, true, true, true, true, true, false};

    if (khbit() && getch() == ' ')
        activate[6] = true;
    else
        activate[6] = false;
    return (activate);
}