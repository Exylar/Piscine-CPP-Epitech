/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &koalaAction) : _koalaAction(koalaAction)
{
    std::vector<char> list_commands;
    std::vector<methodPointer_t> list_actions;

    this->_actions = list_actions;
    this->_commands = list_commands;
}

DomesticKoala::~DomesticKoala()
{
    this->_commands.clear();
    this->_actions.clear();
}

DomesticKoala::DomesticKoala(const DomesticKoala &koalaAction) : _koalaAction(koalaAction._koalaAction), _actions(koalaAction._actions), _commands(koalaAction._commands) {}

DomesticKoala& DomesticKoala::operator=(const DomesticKoala &koalaAction)
{
    this->_commands = koalaAction._commands;
    this->_actions = koalaAction._actions;
    this->_koalaAction = koalaAction._koalaAction;
}

const std::vector<methodPointer_t> * DomesticKoala::getAction() const
{
    return &_actions;
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t methodPointer)
{
    this->_commands.push_back(command);
    this->_actions.push_back(methodPointer);
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    int pos = 0;
    std::vector<char>::iterator itr = std::find(this->_commands.begin(), this->_commands.end(), command);

    if (itr != this->_commands.cend()) {
        pos = std::distance(this->_commands.begin(), itr);
        this->_commands.erase(this->_commands.begin() + pos);
        this->_actions.erase(this->_actions.begin() + pos);
    }
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    int pos = 0;
    std::vector<char>::iterator itr = std::find(this->_commands.begin(), this->_commands.end(), command);

    if (itr != this->_commands.cend()) {
        pos = std::distance(this->_commands.begin(), itr);
        this->_actions[pos];
        std::cout << param << std::endl;
    }
}

void DomesticKoala::setKoalaAction(KoalaAction &koalaAction)
{
    this->_koalaAction = koalaAction;
    this->_actions.clear();
    this->_commands.clear();
}