/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

//-------------------------- Parser -------------------------------//

std::vector<Parser> Parser::split(char delim) const {
    std::stringstream ss(_text);
    std::string token;
    std::vector<Parser> *v = new std::vector<Parser>;

    while (std::getline(ss, token, delim)) {
        if (token != "") {
            v->push_back(Parser(token));
        }
    }
    return (*v);
}

bool Parser::operator==(Parser const& a) {return (getText() == a.getText());}
bool Parser::operator==(std::string const& a) {return (a == _text);}
bool Parser::operator!=(Parser const& a) {return (!(*this == a));}
bool Parser::operator!=(std::string const&a) {return (!(*this == a));}
Parser &Parser::operator+=(Parser const& a) {
    _text += a.getText();
    return (*this);
}
Parser &Parser::operator+=(std::string const &a) {
    _text += a;
    return (*this);
}
Parser &Parser::operator+(Parser const &a) {return (*new Parser(_text + a.getText()));}
Parser &Parser::operator+(std::string const &a) {return (*new Parser(_text + a));}
std::ostream &operator<<(std::ostream &flux, Parser const& a) {
    flux << a.getText();
    return (flux);
}
//-------------------------- FileParser -------------------------------//

void FileParser::readFile(std::string filename) {
    std::ifstream file;
    std::string buff;

    file.open(filename);
    _text = "";
    _filename = filename;
    if (!file) {
        //TODO raise
    }
    while(getline(file, buff)) {
        _text += buff + "\n";
    }
    file.close();
}