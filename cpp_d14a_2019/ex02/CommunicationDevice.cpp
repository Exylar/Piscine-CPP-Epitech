/*
** EPITECH PROJECT, 2020
** cpp_d14a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input,
                                         std::ostream &output)
    try
        : _api(input, output)
    {
    }
    catch (std::exception const &error) {
        throw CommunicationError(std::string("Error: ") + error.what());
    }


CommunicationDevice::~CommunicationDevice()
{
}

void
CommunicationDevice::startMission(std::string const &missionName,
                                  std::string *users,
                                  size_t nbUsers)
{
    try {
        for (size_t i = 0; i < nbUsers; ++i)
            _api.addUser(users[i]);
        _api.startMission(missionName);
    } catch (std::logic_error const &error_logic) {
        throw CommunicationError(std::string("LogicError: ") + error_logic.what());
    } catch (std::runtime_error const &error_run) {
        throw CommunicationError(std::string("RuntimeError: ") + error_run.what());
    } catch (std::exception const &error_ex) {
        throw CommunicationError(std::string("Error: ") + error_ex.what());
    }
}

void
CommunicationDevice::send(std::string const &user,
                          std::string const &message) const
{
    try {
        _api.sendMessage(user, message);
    } catch (std::exception const &error) {
        std::cerr << error.what() << std::endl;
    }
}

void
CommunicationDevice::receive(std::string const &user,
                             std::string &message) const {
    try {
        _api.receiveMessage(user, message);
    } catch (std::exception const &error) {
        std::cerr << error.what() << std::endl << "INVALID MESSAGE";
    }
}