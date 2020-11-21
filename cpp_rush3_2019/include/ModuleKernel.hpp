/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** ModuleKernel
*/

#ifndef MODULEKERNEL_HPP_
#define MODULEKERNEL_HPP_

#include <string>
#include <ctime>
#include "IMonitorModule.hpp"

class ModuleKernel : public IMonitorModule {
	public:
		ModuleKernel();
		~ModuleKernel();

        std::string getKernelVersion() const;
        std::string getSystemName() const;
        float getUptime() const;
        void Display(IMonitorDisplay *iMonitorDisplay) const;
        std::string const &GetName() const;
        void Update();

	private:
        std::string _name;
        std::string _kernelVersion;
        std::string _systemName;
        float _uptime;
};

#endif /* !MODULEKERNEL_HPP_ */
