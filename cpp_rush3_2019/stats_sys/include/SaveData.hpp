/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** SaveData
*/

#ifndef SAVEDATA_HPP_
#define SAVEDATA_HPP_

#include "ModuleKernel.hpp"
#include "ModuleNetwork.hpp"
#include "ModuleCPU.hpp"
#include "ModuleRAM.hpp"
#include "ModuleTime.hpp"
#include "ModuleUserHost.hpp"

class SaveData {
	public:
		SaveData();
		~SaveData();
        void SendTcpPacket() const;
        ModuleCPU getCPU() const;
        ModuleKernel getKernel() const;
        ModuleNetwork getNetwork() const;
        ModuleRAM getRAM() const;
        ModuleTime getTime() const;
        ModuleUserHost getHost() const;
	private:
        ModuleCPU _cpu;
        ModuleKernel _kernel;
        ModuleNetwork _network;
        ModuleRAM _ram;
        ModuleTime _time;
        ModuleUserHost _host;
};

#endif /* !SAVEDATA_HPP_ */
