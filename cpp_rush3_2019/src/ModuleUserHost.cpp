/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** UserHost
*/

#include "ModuleUserHost.hpp"

ModuleUserHost::ModuleUserHost()
{
    this->_name = "";
    this->_hostName = "";
    this->_userName = "";
}

ModuleUserHost::~ModuleUserHost()
{
}

void ModuleUserHost::Update()
{
    std::ifstream file;
    std::stringstream ss;

    file.open("/proc/sys/kernel/hostname");
    if (file.is_open()) {
        ss << file.rdbuf();
        this->_hostName = ss.str();
        file.close();
    }
    this->_userName = std::getenv("USER");
}

void ModuleUserHost::Display(IMonitorDisplay *d) const
{
    d->DisplaySeparator();
    d->DisplayTitle("User/Host Module (R)");
    d->DisplaySubTitle("Hostname :");
    d->DisplayText(_hostName);
    d->DisplaySubTitle("Username :");
    d->DisplayText(_userName);
}

std::string const &ModuleUserHost::GetName() const { return this->_name; }
std::string ModuleUserHost::GetHostName() const { return this->_hostName; }
std::string ModuleUserHost::GetUserName() const { return this->_userName; }