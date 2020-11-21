/*
** EPITECH PROJECT, 2019
** cpp_d13_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "ToyStory.hpp"

void ToyStory::tellMeAStory(const std::string filename, Toy &toy1, bool (Toy::*func)(std::string), Toy &toy2, bool (Toy::*func2)(std::string))
{
    std::fstream fs;
    std::string line;
    int rotation = 0;

    fs.open(filename, std::fstream::in);
    if (!fs.is_open()) {
        std::cout << "Bad Story" << std::endl;
        fs.close();
        return;
    }

    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;

    while (std::getline(fs, line)) {
        if (line.substr(0, 8) == "picture:") {
            if (rotation %  2 == 0) {
                if (!toy1.setAscii(line.substr(8))) {
                    std::cout << toy1.getLastError().where() << ": "
                              << toy1.getLastError().what() << std::endl;
                    return;
                }
                else
                    std::cout << toy1.getAscii() << std::endl;
            }
            else {
                if (!toy2.setAscii(line.substr(8))) {
                    std::cout << toy2.getLastError().where() << ": "
                              << toy2.getLastError().what() << std::endl;
                    return;
                }
                else
                    std::cout << toy2.getAscii() << std::endl;
            }
        } else {
            if (rotation % 2 == 0)
                (toy1.*func)(line);
            else
                (toy2.*func2)(line);
            rotation++;
        }
    }
    return;
}