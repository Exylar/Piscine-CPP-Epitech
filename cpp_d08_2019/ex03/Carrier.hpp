/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D08_2019_CARRIER_HPP
#define CPP_D08_2019_CARRIER_HPP

#include "Droid.hpp"

class Carrier {
    public:
        Carrier(std::string id);
        ~Carrier();
        Carrier &operator<<(Droid *droid);
        Carrier &operator>>(Droid *droid);
        Droid &operator[](int nb) const;
        void operator<<(Droid *droid);
        const Droid &operator[](size_t const nb) const;
        Carrier &operator~();
        bool operator()(int x, int y);
        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        size_t getSpeed() const;
        size_t getCount() const;
        void setId(std::string id);
        void setEnergy(size_t energy);
        void setToughness(size_t toughness);
        void setSpeed(size_t speed);
    private:
        std::string _Id = "";
        size_t _Energy = 300;
        const size_t _Attack = 100;
        size_t _Toughness = 90;
        size_t _Speed = 0;
        Droid *Droids[5] = {NULL, NULL, NULL, NULL, NULL};
};

std::ostream &operator<<(std::ostream &out, const Carrier &carrier);

#endif //CPP_D08_2019_CARRIER_HPP
