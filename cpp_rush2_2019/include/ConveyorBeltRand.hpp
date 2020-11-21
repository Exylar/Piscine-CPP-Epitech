/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ConveyorBeltRand
*/

#ifndef CONVEYORBELTRAND_HPP_
#define CONVEYORBELTRAND_HPP_

#include "IConveyorBelt.hpp"
#include "XMLParser.hpp"

class ConveyorBeltRand : public IConveyorBelt
{
    public:
        ConveyorBeltRand();
        ~ConveyorBeltRand() override;

        Object *take() override;
        bool put(Object *&obj);
        void operator<<(Object *&obj) override;

        bool in() override;
        bool out() override;

        bool isEmpty() const override;
        bool writeFile(Object *obj);

    private:
        static int i;

        Object *obj;
        XMLParser parser;
};

#endif /* !CONVEYORBELTRAND_HPP_ */
