/*
** EPITECH PROJECT, 2019
** cpp_d13_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Toy.hpp"

Toy::Toy() : _name("toy"), _type(BASIC_TOY), _filename("")
{
    this->_picture = new Picture();
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

    if (stat (filename.c_str(), &buffer) == 0) {
        if (!this->_picture)
            this->_picture = new Picture(filename);
        this->_filename = filename;
        return this->_picture->getPictureFromFile(filename);
    }
    else
        return false;

}