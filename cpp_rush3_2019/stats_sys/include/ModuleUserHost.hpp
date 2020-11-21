/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** UserHost
*/

#ifndef USERHOST_HPP_
#define USERHOST_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "IMonitorModule.hpp"

class ModuleUserHost : public IMonitorModule {
	public:
		ModuleUserHost();
		~ModuleUserHost();

		void Update();
        void Display(IMonitorDisplay *iMonitorDisplay) const;
        std::string const &GetName() const;
        std::string GetHostName() const;
        std::string GetUserName() const;
	private:
        std::string _name;
        std::string _hostName;
        std::string _userName;
};

#endif /* !USERHOST_HPP_ */
