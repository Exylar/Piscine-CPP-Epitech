/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D10_2019_AWEAPON_HPP
#define CPP_D10_2019_AWEAPON_HPP

#include <iostream>

class AWeapon {
    public:
        AWeapon(const std::string &name, int damage, int apcost);
        virtual ~AWeapon();
        virtual void Attack() const = 0;
        std::string getName() const;
        int getAPCost() const;
        int getDamage() const;
        void setAPCost(int apcost);
        void setDamage(int damage);
        void setName(std::string name);
    protected:
        std::string _name;
        int _damage;
        int _ap_cost;
};

#endif //CPP_D10_2019_AWEAPON_HPP
