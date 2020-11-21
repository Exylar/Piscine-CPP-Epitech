/*
** EPITECH PROJECT, 2019
** cpp_d13_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D13_2019_TOY_HPP
#define CPP_D13_2019_TOY_HPP

#include <sys/stat.h>
#include <iostream>
#include "Picture.hpp"

class Toy {
    public:
    enum ToyType { BASIC_TOY, ALIEN };
    Toy();
    Toy(ToyType type, const std::string &name, const std::string filename);
    ~Toy();

    // Getter
    ToyType getType() const;
    std::string getName() const;
    std::string getAscii() const;

    //setter
    void setName(const std::string &name);
    bool setAscii(const std::string &filename);

    private:
        std::string _name;
        ToyType _type;
        std::string _filename;
        Picture *_picture;
};

#endif //CPP_D13_2019_TOY_HPP
