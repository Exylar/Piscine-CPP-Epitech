/*
** EPITECH PROJECT, 2019
** cpp_rush2_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_RUSH2_2019_SERIALIZER_HPP
#define CPP_RUSH2_2019_SERIALIZER_HPP

#include <fstream>
#include <iostream>
#include "Object.hpp"
#include "Wrap.hpp"
#include "Toy.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"

class XMLParser
{
    public:
        XMLParser();
        ~XMLParser();
        bool CheckFile(std::string nameFile) const;
        std::string SerializeString(Object *object);
        Object *Deserializer(std::string string);
    private:
        const std::string _version = "1.0";
        const std::string _enconding = "UTF-8";
};

#endif //CPP_RUSH2_2019_SERIALIZER_HPP
