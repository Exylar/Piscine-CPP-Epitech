/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D10_2019_CHARACTER_HPP
#define CPP_D10_2019_CHARACTER_HPP

#include "AWeapon.hpp"
#include "AEnemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include <iostream>

class Character {
    public:
        Character(const std::string &name);
        virtual ~Character();
        void recoverAP();
        void equip(AWeapon *weapon);
        void attack(AEnemy *enemy);
        std::string const &getName() const;
        int getAp() const;
        AWeapon *getWeapon() const;
    private:
        const std::string _name;
        AWeapon *_weapon;
        int _AP = 40;
};

std::ostream &operator<<(std::ostream &out, const Character &character);


#endif //CPP_D10_2019_CHARACTER_HPP
