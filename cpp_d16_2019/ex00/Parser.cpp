/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Parser.hpp"


int DoOp(int num1, int num2, char ope)
{
    if (ope == '+') { return num1 + num2; }
    if (ope == '-') { return num1 - num2; }
    if (ope == '*') { return num1 * num2; }
    if (ope == '/') { return num1 / num2; }
    if (ope == '%') { return num1 % num2; }
}

Parser::Parser()
{
    std::stack<char>operators;
    std::stack<int>operands;

    this->_result = 0;
    this->_operands = operands;
    this->_operators = operators;
}

Parser::~Parser() {}

void Parser::feed(const std::string &string)
{
    std::string result;
    int num1;
    int num2;
    float test;
    char last_operands;

    if (this->_result != 0)
        this->_operators.push('+');

    for(std::string::size_type i = 0; i < string.size(); ++i) {
        if (string[i] == ' ')
            continue;
        if (string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '/' || string[i] == '%') {
            if (result != "")
                this->_operands.push(std::atoi(result.c_str()));
            result = "";
            this->_operators.push(string[i]);
        }
        else if (string[i] == '(' || string[i] == ')' ) {
            if (string[i] == ')') {
                if (result != "")
                    this->_operands.push(std::atoi(result.c_str()));
                result = "";
                num2 = this->_operands.top();
                this->_operands.pop();
                last_operands = this->_operators.top();
                this->_operators.pop();
                num1 = this->_operands.top();
                this->_operands.pop();
                test = DoOp(num1, num2, last_operands);
                this->_operands.push(test);
                this->_result = test;
            }
        }
        else
            result += string[i];
    }
    if (this->_operands.size() > 1) {;
        num2 = this->_operands.top();
        this->_operands.pop();
        last_operands = this->_operators.top();
        this->_operators.pop();
        num1 = this->_operands.top();
        this->_operands.pop();
        this->_operands.push(DoOp(num1, num2, last_operands));
    }
    this->_result = this->_operands.top();
    this->_operands.empty();
    this->_operands.push(this->_result);
    this->_operators.empty();
}

void Parser::reset()
{
    _result = 0;
    while (!this->_operands.empty())
        this->_operands.pop();
    while (!this->_operators.empty())
        this->_operators.pop();
}

int Parser::result() const
{
    return _result;
}