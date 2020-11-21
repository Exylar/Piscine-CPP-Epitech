/*
** EPITECH PROJECT, 2019
** cpp_rush2_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <iostream>
#include <fstream>
#include "XMLParser.hpp"

int main(int argc, char *argv[])
{
    Object *present;
    XMLParser *output = new XMLParser;
    std::ifstream iss;

    for (int i = 1; i < argc; i++) {
        iss.open(argv[i]);
        if (!iss.is_open())
            return 1;
        std::string str((std::istreambuf_iterator<char>(iss)),
                    std::istreambuf_iterator<char>());

        present = output->Deserializer(str);
        if (present == nullptr) {
            std::cout << "Nothing came out of that..." << std::endl;
            continue;
        }
        while (present->canWrap()) {
            Wrap *wrap = (Wrap *)present;
            std::cout << "Unwrapping: " << wrap->getTitle() << std::endl;
            wrap->openMe();
            present = wrap->getContent();
            delete wrap;
        }
        std::cout << "The gift that was in the box: " << present->getTitle() << std::endl;
        delete present;
        iss.close();
    }
    return 0;
}