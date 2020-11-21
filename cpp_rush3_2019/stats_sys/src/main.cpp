/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** main
*/

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include <chrono>
#include <thread>
#include "Parser.hpp"
#include "ModuleRAM.hpp"
#include "ModuleCPU.hpp"
#include "ModuleKernel.hpp"
#include "ModuleNetwork.hpp"
#include "ModuleTime.hpp"
#include "ModuleUserHost.hpp"

void print_cpu(std::ofstream &file)
{
    ModuleCPU m;

    m.Update();
    file << "Model=" << m.getModel() << std::endl;
    file << "Frequency="<< m.getFrequency() << std::endl;
    file << "NbCores=" << m.getNbCores() << std::endl;
    file << "Activity=" << m.getActivity() << "%" << std::endl;
}

void print_mem(std::ofstream &file) {
    ModuleRAM m;

    m.Update();
    file << "mem total=" << m.getMemTotal() << std::endl;
    file << "mem free=" << m.getMemFree() << std::endl;
    file << "swap total=" << m.getSwapTotal() << std::endl;
    file << "swap free=" << m.getSwapFree() << std::endl;
}

void print_kernel(std::ofstream &file)
{
    ModuleKernel Kernel;
    
    Kernel.Update();
    file << "Name=" << Kernel.GetName() << std::endl;
    file << "SystemName=" << Kernel.getSystemName() << std::endl;
    file << "Uptime=" << Kernel.getUptime() << std::endl;
    file << "KernelVersion=" << Kernel.getKernelVersion() << std::endl;
}

void print_network(std::ofstream &file)
{
    ModuleNetwork Network;

    Network.Update();
    file << "Download=" << Network.GetDownload() << " kb/s" << std::endl;
    file << "Upload=" << Network.GetUpload() << " kb/s" << std::endl;
}

void print_Time(std::ofstream &file)
{
    ModuleTime Time;

    Time.Update();
    file << "Date=" << Time.GetDate()  << std::endl;
    file << "Heure=" << Time.GetTime() << std::endl;
}

void print_UserHost(std::ofstream &file)
{
    ModuleUserHost UserHost;

    UserHost.Update();
    file << "Hostname=" << UserHost.GetHostName();
    file << "Username=" << UserHost.GetUserName() << std::endl;
}

int main()
{
    std::ofstream file;
    file.open(".stat", std::fstream::out);
    if (file.bad()) {
        std::cerr << "[ERROR] : Can't create a save of your data system!" << std::endl; 
        return 84;
    }
    print_cpu(file);
    print_mem(file);
    print_kernel(file);
    print_network(file);
    print_Time(file);
    print_UserHost(file);
    file.close();
}