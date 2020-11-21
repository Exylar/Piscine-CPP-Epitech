/*
** EPITECH PROJECT, 2020
** cpp_d14a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D14A_2019_ERROR_HPP
#define CPP_D14A_2019_ERROR_HPP

#include <iostream>
#include <string>

class NasaError : public std::exception
{
    public:
        NasaError(std::string const &message,
                  std::string const &component = "Unknown");
        std::string const &getComponent() const;

        const char *what() const noexcept;
    protected:
        std::string _component;
        std::string _message;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message,
                             std::string const &component = "Unknown");
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message,
                          std::string const &component = "Unknown");
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message,
                  std::string const &component = "Unknown");
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
};

#endif //CPP_D14A_2019_ERROR_HPP
