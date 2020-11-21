/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** SaveData
*/

#include <fstream>
#include "../include/SaveData.hpp"

SaveData::SaveData()
{
    this->_cpu 
}

SaveData::~SaveData()
{
}

ModuleCPU SaveData::getCPU() const { return this->_cpu; }
ModuleKernel SaveData::getKernel() const { return this->_kernel; }
ModuleNetwork SaveData::getNetwork() const { return this->_network; }
ModuleRAM SaveData::getRAM() const { return this->_ram; }
ModuleUserHost SaveData::getHost() const { return this->_host; }
ModuleTime SaveData::getTime() const { return this->_time; }

void SaveData::SendTcpPacket() const;
{
    std::ofstream File(".stats");

}