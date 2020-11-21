/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Time
*/

#ifndef TIME_HPP_
#define TIME_HPP_

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include "IMonitorModule.hpp"

class ModuleTime : public IMonitorModule {
	public:
		ModuleTime();
		~ModuleTime();

		void Update();
        void Display(IMonitorDisplay *iMonitorDisplay) const;
        std::string const &GetName() const;
        std::string GetDate() const;
        std::string GetTime() const;
	private:
        std::string _name;
        std::string _date;
        std::string _time;
};

#endif /* !TIME_HPP_ */
