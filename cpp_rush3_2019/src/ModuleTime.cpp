/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Time
*/

#include <stdio.h>
#include <time.h>
#include <string>
#include "ModuleTime.hpp"

ModuleTime::ModuleTime()
{
    this->_name = "Time";
    this->_date = "";
    this->_time = "";
}

ModuleTime::~ModuleTime()
{
}

void ModuleTime::Update()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,80,"%d %m %Y",timeinfo);
    this->_date = buffer;
    strftime (buffer,80,"%H:%M:%S",timeinfo);
    this->_time = buffer;
}

void ModuleTime::Display(IMonitorDisplay *d) const
{
    d->DisplaySeparator();
    d->DisplayTitle("Time Module (Y)");
    d->DisplaySubTitle("Date :");
    d->DisplayText(_date);
    d->DisplaySubTitle("Time :");
    d->DisplayText(_time);
}

std::string const &ModuleTime::GetName() const { return this->_name; }
std::string ModuleTime::GetDate() const { return this->_date; }
std::string ModuleTime::GetTime() const { return this->_time; }
