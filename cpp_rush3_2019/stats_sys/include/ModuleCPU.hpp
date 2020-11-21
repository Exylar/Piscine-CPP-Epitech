/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** ModuleCPU
*/

#ifndef MODULECPU_HPP_
#define MODULECPU_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include "Parser.hpp"
#include "IMonitorModule.hpp"

class ModuleCPU : public IMonitorModule {
	public:
        //Ctor
	ModuleCPU();
        //Dtor
        ~ModuleCPU();


        void Update();
        void Display(IMonitorDisplay *iMonitorDisplay) const;

        std::string const &GetName() const;
        std::string getModel() const;
        float getFrequency() const;
        size_t getNbCores() const;
        float getActivity() const;

        private:
        void updateCPUUsage();
        void updateCPUInfo();

	private:
        std::string _name;
        std::string _model;
        float _frequency;
        size_t _nb_of_cores;
        float _activity;
};

#endif /* !MODULECPU_HPP_ */
