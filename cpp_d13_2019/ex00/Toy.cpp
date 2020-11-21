/*
** EPITECH PROJECT, 2019
** cpp_d13_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Toy.hpp"

Toy::Toy() : _name("Toy"), _type(BASIC_TOY), _filename("")
{
    this->_picture = new Picture();
}

Toy::Toy(Toy::ToyType type, const std::string &name, const std::string filename) : _name(name), _type(type), _filename(filename)
{
    this->_picture = new Picture(filename);
}

Toy::~Toy()
{
    delete this->_picture;
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