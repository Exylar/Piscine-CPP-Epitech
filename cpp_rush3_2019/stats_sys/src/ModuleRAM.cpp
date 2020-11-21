/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** ModuleRAM
*/

#include "ModuleRAM.hpp"

static size_t stringToSizeT(std::string const& s) {
    std::stringstream sstream(s);
    size_t result;

    sstream >> result;
    return (result);
}

ModuleRAM::ModuleRAM()
{
    _name = "ModuleRAM";
    _memTotal = 0;
    _memFree = 0;
    _swapTotal = 0;
    _swapFree = 0;
}


//-------------------------- methods -------------------------------//
void ModuleRAM::Update() {
    FileParser p(MEMPROC);
    std::vector<Parser> pv = p.split('\n');
    std::vector<Parser>::iterator it;
    for (it = pv.begin(); it != pv.end(); it++) {
        std::vector<Parser> data = it->split(' ');
        if (data[0] == "MemTotal:") {
            _memTotal = stringToSizeT(data[1].getText());
        } else if (data[0] == "MemFree:") {
            _memFree = stringToSizeT(data[1].getText());
        } else if (data[0] == "SwapTotal:") {
            _swapTotal = stringToSizeT(data[1].getText());
        } else if (data[0] == "SwapFree:") {
            _swapFree = stringToSizeT(data[1].getText());
        }
    }
}

void ModuleRAM::Display(IMonitorDisplay *iMonitorDisplay) const {
    (void)iMonitorDisplay;
}

//-------------------------- getters -------------------------------//
std::string const &ModuleRAM::GetName() const { return (this->_name);}
size_t ModuleRAM::getMemTotal() const {return (_memTotal);}
size_t ModuleRAM::getMemFree() const {return (_memFree);}
size_t ModuleRAM::getSwapTotal() const {return (_swapTotal);}
size_t ModuleRAM::getSwapFree() const {return (_swapFree);}