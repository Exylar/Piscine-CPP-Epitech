/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D16_2019_PARSER_HPP
#define CPP_D16_2019_PARSER_HPP

#include <stack>
#include <iostream>
#include <string>

class Parser {
    public:
        Parser();
        ~Parser();
        void feed(const std::string &string);
        int result() const;
        void reset();
    private:
        int _result;
        std::stack<char> _operators;
        std::stack<int> _operands;
};

#endif //CPP_D16_2019_PARSER_HPP
