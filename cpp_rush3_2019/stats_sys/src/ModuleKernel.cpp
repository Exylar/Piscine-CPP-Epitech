/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** ModuleKernel
*/

#include <iostream>
#include <fstream>
#include <string>
#include "const.hpp"
#include "ModuleKernel.hpp"

static std::string get_kernel(std::string path)
{
    std::ifstream file(path);
	if (!file)
    {
        std::cout << "File version not found" << std::endl;
        return "";
    }
    std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    while (str.find("\n") != std::string::npos)
        str.replace(str.find("\n"), 1, "");
    return str;
}

ModuleKernel::ModuleKernel()
{
    Update();
}

ModuleKernel::~ModuleKernel()
{
}

void ModuleKernel::Display(IMonitorDisplay *iMonitorDisplay) const
{
    (void)iMonitorDisplay;
}

void ModuleKernel::Update()
{
    this->_name = "ModuleKernel";
    this->_systemName = get_kernel(OSRELEASEPROC);
    this->_kernelVersion = get_kernel(OSTYPEPROC);
    this->_uptime = std::stof(get_kernel(UPTIMEPROC));
}

std::string const &ModuleKernel::GetName() const { return this->_name; }
std::string ModuleKernel::getKernelVersion() const { return this->_kernelVersion; }
std::string ModuleKernel::getSystemName() const { return this->_systemName; }
float ModuleKernel::getUptime() const { return this->_uptime; }