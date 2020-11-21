/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** Parser.hpp
*/

#ifndef EE2D197C_7C98_41EC_A684_01BCEAEAAB81
#define EE2D197C_7C98_41EC_A684_01BCEAEAAB81

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class Parser {
    public:
    Parser() : _text(""){};
    Parser(std::string text) : _text(text){};
    ~Parser() {};

    //-------------------------- methods -------------------------------//
    std::vector<Parser> split(char delim) const;
    //-------------------------- operators -------------------------------//
    bool operator==(Parser const& a);
    bool operator==(std::string const& a);
    bool operator!=(Parser const& a);
    bool operator!=(std::string const& a);
    Parser &operator+=(Parser const& a);
    Parser &operator+=(std::string const& a);
    Parser &operator+(Parser const& a);
    Parser &operator+(std::string const& a);

    //-------------------------- getSet -------------------------------//
    void setText(std::string const& text) {_text = text;};
    std::string getText() const {return (_text);};
    //-------------------------- members -------------------------------//
    protected:
    std::string _text;
};

std::ostream &operator<<(std::ostream &flux, Parser const& a);

class FileParser : public Parser{
    public:
    FileParser(std::string filename) : Parser() {readFile(filename);};
    FileParser() : Parser(""), _filename("") {};
    ~FileParser() {};

    //-------------------------- methods -------------------------------//
    void readFile(std::string filename);
    //-------------------------- get/set -------------------------------//
    protected:
    std::string _filename;
};

#endif /* EE2D197C_7C98_41EC_A684_01BCEAEAAB81 */

