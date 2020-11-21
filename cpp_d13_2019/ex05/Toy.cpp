/*
** EPITECH PROJECT, 2019
** cpp_d13_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Toy.hpp"

Toy::Toy() : _name("toy"), _type(BASIC_TOY), _filename("")
{
    Error *error = new Error();

    this->_picture = new Picture();
    this->_error = *error;
}

Toy::Toy(Toy::ToyType type, const std::string &name, const std::string filename) : _name(name), _type(type), _filename(filename)
{
    this->_picture = new Picture(filename);
}

Toy::Toy(const Toy &toy) : _name(toy._name), _type(toy._type), _filename(toy._filename), _picture(toy._picture) {}

Toy& Toy::operator=(const Toy &toy)
{
    this->_name = toy._name;
    this->_type = toy._type;
    this->_filename = toy._filename;
    this->_picture = toy._picture;
    return *this;
}

Toy::~Toy() {}

void Toy::speak(const std::string statement)
{
    std::cout << this->_name << " \"" << statement << "\"" << std::endl;
}

bool Toy::speak_es(const std::string statement)
{
    (void)statement;
    this->_error.type = Toy::Error::SPEAK;
    return false;
}

Toy& Toy::operator<<(std::string string)
{
    this->_picture->_data = string;
    return *this;
}

std::string Toy::getName() const
{
    return this->_name;
}

Toy::ToyType Toy::getType() const
{
    return this->_type;
}

std::string Toy::getAscii() const
{
    if (this->_picture)
        return this->_picture->_data;
    else
        return "ERROR";
}

void Toy::setName(const std::string &name)
{
    this->_name = name;
}

bool Toy::setAscii(const std::string &filename)
{
    struct stat buffer;

    this->_error.type = Toy::Error::UNKNOWN;
    if (stat (filename.c_str(), &buffer) == 0) {
        if (!this->_picture)
            this->_picture = new Picture(filename);
        this->_filename = filename;
        this->_error.type = Toy::Error::UNKNOWN;
        return this->_picture->getPictureFromFile(filename);
    }
    else {
        this->_error.type = Toy::Error::PICTURE;
        return false;
    }
}

Toy::Error::Error() {}

Toy::Error::~Error() {}

Toy::Error Toy::getLastError() const
{
    return this->_error;
}

std::string Toy::Error::what() const
{
    if (this->type == SPEAK)
        return "wrong mode";
    else if (this->type == PICTURE)
        return "bad new illustration";
    return "";
}

std::string Toy::Error::where() const
{
    if (this->type == SPEAK)
        return "speak_es";
    else if (this->type == PICTURE)
        return "setAscii";
    return "";
}

std::ostream &operator<<(std::ostream &out, const Toy &toy)
{
    out << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return out;
}