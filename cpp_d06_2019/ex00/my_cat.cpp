/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
    std::ifstream fs;

    if (argc == 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]\n";
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        std::string filename = argv[i];
        fs.open(filename);
        if (fs.is_open()) {
            std::cout << fs.rdbuf();
            fs.close();
        }
        else
            std::cerr << "my_cat: " << filename << ": No such file or directory\n";
    }
    return 0;
}