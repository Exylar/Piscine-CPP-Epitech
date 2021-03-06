/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** ModuleNetwork
*/

#ifndef MODULENETWORK_HPP_
#define MODULENETWORK_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <string.h>
#include "IMonitorModule.hpp"


class ModuleNetwork : public IMonitorModule {
	public:
		ModuleNetwork();
		~ModuleNetwork();

		void Update();
        void Display(IMonitorDisplay *iMonitorDisplay) const;
        std::string const &GetName() const;
        float GetUpload() const;
        float GetDownload() const;
	private:
        std::string _name;
        float _upload;
        float _download;
};

#endif /* !MODULENETWORK_HPP_ */
