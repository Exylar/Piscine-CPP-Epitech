/*
** EPITECH PROJECT, 2019
** cpp_d07a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D07A_2019_SKAT_HPP
#define CPP_D07A_2019_SKAT_HPP

#include <iostream>

class Skat {
    public :
        Skat();
        Skat(const std::string &name, int stimPaks);
        ~Skat();
        int& stimPaks();
        const std::string &name();
        void shareStimPaks (int number, int& stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();
    private:
        std::string _name = "bob";
        int _stimPaks = 15;
};


#endif //CPP_D07A_2019_SKAT_HPP
