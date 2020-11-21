/*
** EPITECH PROJECT, 2020
** cpp_d14a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Errors.hpp"

NasaError::NasaError(const std::string &message, const std::string &component)
{
    this->_component = component;
    this->_message = message;
}

const std::string &NasaError::getComponent() const
{
    return _component;
}

const char *NasaError::what() const noexcept
{
    return _message.c_str();
}

MissionCriticalError::MissionCriticalError(const std::string &message, const std::string &component) : NasaError(message, component) {}


LifeCriticalError::LifeCriticalError(const std::string &message, const std::string &component) : NasaError(message, component) {}


UserError::UserError(const std::string &message, const std::string &component) : NasaError(message, component) {}


CommunicationError::CommunicationError(const std::string &message) : NasaError(message, "CommunicationDevice") {}


