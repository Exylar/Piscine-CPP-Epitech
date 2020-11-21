/*
** EPITECH PROJECT, 2019
** cpp_d14m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D14M_2019_FRUIT_HPP
#define CPP_D14M_2019_FRUIT_HPP

#include <string>

class Fruit {
    public:
        Fruit(const std::string &name, int vitamins);
        ~Fruit();
        Fruit(const Fruit &fruit);
        Fruit &operator=(const Fruit &fruit);

        //Getter
        int getVitamins() const;
        std::string getName() const;

        //Setter
        void setVitamins(int vitamins);
        void setName(const std::string name);

    protected:
        std::string _name;
        int _vitamins;
};

#endif //CPP_D14M_2019_FRUIT_HPP
