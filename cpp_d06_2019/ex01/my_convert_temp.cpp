/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>

int main() {
    std::string line;
    std::getline(std::cin, line);

    int pos = line.find(" ");
    std::string unit = line.substr(0, pos);
    std::string sub = line.substr(pos + 1);

    try {
        (stof(unit));
    }
    catch (int e) {
        return 84;
    }

    if (sub.compare("Celsius") == 0) {
        double value = ((stof(unit) / (5.0 / 9.0)) + 32.0);
        std::cout << std::fixed  << std::setprecision(3) << std::setw(16) << value << std::setw(16)<< "Fahrenheit" << "\n";
    }
    else if (sub.compare("Fahrenheit") == 0) {
        double value = 5.0 / 9.0 * ((stof(unit)) - 32.0);
        std::cout << std::fixed << std::setprecision(3) << std::setw(16) << value << std::setw(16) << "Celsius" << "\n";
    }
    else
        return 84;

    return 0;
}