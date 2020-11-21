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
#include <list>
#include "Parser.hpp"
#include "ModuleRAM.hpp"
#include "ModuleCPU.hpp"
#include "ModuleKernel.hpp"
#include "ModuleNetwork.hpp"
#include "ModuleTime.hpp"
#include "ModuleUserHost.hpp"
#include "DisplaySFML.hpp"
#include "DisplayNcurses.hpp"

void print_cpu()
{
    ModuleCPU m;

    m.Update();
    std::cout << m.getModel() << std::endl;
    std::cout << m.getFrequency() << std::endl;
    std::cout << m.getNbCores() << std::endl;
    std::cout << m.getActivity() << "%" << std::endl;
}

void print_mem() {
    ModuleRAM m;

    m.Update();
    std::cout << "mem total: " << m.getMemTotal() << std::endl;
    std::cout << "mem free: " << m.getMemFree() << std::endl;
    std::cout << "swap total: " << m.getSwapTotal() << std::endl;
    std::cout << "swap free: " << m.getSwapFree() << std::endl;
}

void print_kernel()
{
    ModuleKernel Kernel;
    Kernel.Update();
    std::cout << Kernel.GetName() << std::endl; 
    std::cout << Kernel.getSystemName() << std::endl; 
    std::cout << Kernel.getUptime() << std::endl;
    std::cout << Kernel.getKernelVersion() << std::endl; 
}

void print_network()
{
    ModuleNetwork Network;

    Network.Update();
    std::cout << "Download: " << Network.GetDownload() << " kb/s" << std::endl;
    std::cout << "Upload: " << Network.GetUpload() << " kb/s" << std::endl;
}

void print_Time()
{
    ModuleTime Time;

    Time.Update();
    std::cout << "Date: " << Time.GetDate()  << std::endl;
    std::cout << "Heure: " << Time.GetTime() << std::endl;
}

void print_UserHost()
{
    ModuleUserHost UserHost;

    UserHost.Update();
    std::cout << "Hostname: " << UserHost.GetHostName();
    std::cout << "Username: " << UserHost.GetUserName() << std::endl;
}

void useModule(IMonitorModule *m, IMonitorDisplay *d) {
    m->Update();
    m->Display(d);
}

int main()
{
    //IMonitorDisplay *ncurses = new DisplayNcurses();
    //IMonitorDisplay *sfml = new DisplaySFML();
    IMonitorDisplay *display = new DisplayNcurses();;

    IMonitorModule *cpu = new ModuleCPU();
    IMonitorModule *ram = new ModuleRAM();
    IMonitorModule *kernel = new ModuleKernel();
    IMonitorModule *uh = new ModuleUserHost();
    IMonitorModule *network = new ModuleNetwork();
    IMonitorModule *time_ = new ModuleTime();
    bool graphical = false;

    bool *activate;
    cbreak();
    noecho();

    while (display->isOpen()) {
        activate = display->GetModules();
        if (activate[0])
            useModule(cpu, display);
        if (activate[1])
            useModule(ram, display);
        if (activate[2])
            useModule(kernel, display);
        if (activate[3])
            useModule(uh, display);
        if (activate[4])
            useModule(network, display);
        if (activate[5])
            useModule(time_, display);
        if (activate[6]) {
            delete(display);
            graphical = !graphical;
            if (graphical)
                display = new DisplaySFML();
            else
                display = new DisplayNcurses();
        }
        display->Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    delete(display);
    delete(cpu);
    delete(ram);
    delete(kernel);
    delete(uh);
    delete(network);
    delete(time_);

    return 0;
}