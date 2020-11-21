/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D08_2019_DROID_HPP
#define CPP_D08_2019_DROID_HPP

#include <iostream>

class Droid {
    public:
        Droid(std::string id);
        Droid();
        Droid(const Droid &droid);
    ~Droid();
        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;
        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);
        Droid &operator<<(size_t &energy);
        Droid &operator=(const Droid &droid);
        bool operator==(const Droid &droid) const;
        bool operator!=(const Droid &droid) const;
    private:
        std::string _Id = "";
        size_t _Energy = 50;
        const size_t _Attack = 25;
        const size_t _Toughness = 15;
        std::string _Status = std::string("Standing by");
};

std::ostream &operator<<(std::ostream &out, const Droid &droid);

#endif //CPP_D08_2019_DROID_HPP
