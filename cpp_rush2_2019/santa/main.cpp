/*
** EPITECH PROJECT, 2019
** cpp_rush2_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "ArgsParser.hpp"
#include "XMLParser.hpp"


int main(int argc, const char **argv)
{
    ArgsParser argsParser;

    if (argsParser.checkArgs(argc, argv) == -1)
        return 84;
    return 0;
}