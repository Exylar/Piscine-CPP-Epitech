/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** MagicalCarpet
*/

#ifndef MAGICALCARPET_HPP_
#define MAGICALCARPET_HPP_

#include "IConveyorBelt.hpp"
#include "XMLParser.hpp"

class MagicalCarpet : public IConveyorBelt
{
    public:
        MagicalCarpet(std::string ip);
        ~MagicalCarpet() override;

        Object *take() override;
        void operator<<(Object *&obj) override;
        bool put(Object *&obj);

        bool in() override;
        bool out() override;

        bool isEmpty() const override;

        bool sendNetwork(std::string message) const;
    private:
        Object *obj;
        std::string ip;
        XMLParser parser;
};

#endif /* !MAGICALCARPET_HPP_ */