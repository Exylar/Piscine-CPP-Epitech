/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** ModuleRAM
*/

#ifndef MODULERAM_HPP_
#define MODULERAM_HPP_

#include <string>
#include <fstream>
#include "Parser.hpp"
#include "IMonitorModule.hpp"
#include "const.hpp"
#include <iostream>

class ModuleRAM : public IMonitorModule {
	public:
        ModuleRAM();
        ~ModuleRAM() {};

        //-------------------------- methods -------------------------------//
        void Update();
        void Display(IMonitorDisplay *iMonitorDisplay) const;
        
        //-------------------------- getters -------------------------------//
        std::string const &GetName() const;
        size_t getMemTotal() const;
        size_t getMemFree() const;
        size_t getSwapTotal() const;
        size_t getSwapFree() const;

        //-------------------------- members -------------------------------//
	private:
        std::string _name;
        size_t _memTotal;
        size_t _memFree;
        size_t _swapTotal;
        size_t _swapFree;
};

#endif /* !MODULERAM_HPP_ */
