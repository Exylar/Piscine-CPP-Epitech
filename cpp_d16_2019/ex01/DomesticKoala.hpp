/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D16_2019_DOMESTICKOALA_HPP
#define CPP_D16_2019_DOMESTICKOALA_HPP

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include "KoalaAction.hpp"

class DomesticKoala {
    public:
        DomesticKoala(KoalaAction &koalaAction);
        ~DomesticKoala();
        DomesticKoala(const DomesticKoala &koalaAction);
        DomesticKoala &operator=(const DomesticKoala &koalaAction);

        using methodPonter_t = methodPointer_t;
        const std::vector<methodPointer_t> *getAction() const;
        void learnAction(unsigned char command, methodPointer_t methodPointer);
        void unlearnAction(unsigned char command);
        void doAction(unsigned char command, const std::string &param);
        void setKoalaAction(KoalaAction &koalaAction);
    private:
        KoalaAction _koalaAction;
        std::vector<char> _commands;
        std::vector<methodPointer_t> _actions;
};

#endif //CPP_D16_2019_DOMESTICKOALA_HPP
