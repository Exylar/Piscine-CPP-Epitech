/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D10_2019_AENEMY_HPP
#define CPP_D10_2019_AENEMY_HPP

#include <iostream>

class AEnemy {
    public:
        AEnemy(int hp, const std::string &type);
        virtual ~AEnemy();
        virtual void takeDamage(int damage);
        std::string const& getType() const;
        int getHP() const;
    protected:
        int _hp;
        const std::string _type;
};

#endif //CPP_D10_2019_AENEMY_HPP
