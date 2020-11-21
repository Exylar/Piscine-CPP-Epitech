/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** IConveyorBelt
*/

#ifndef ICONVEYORBELT_HPP_
#define ICONVEYORBELT_HPP_

#include "Object.hpp"

class IConveyorBelt {
    public:
        virtual ~IConveyorBelt() {}

        virtual Object *take() = 0;
        virtual bool put(Object *&obj) = 0;
        virtual void operator<<(Object *&obj) = 0;

        virtual bool in() = 0;
        virtual bool out() = 0;

        virtual bool isEmpty() const = 0;
};

IConveyorBelt *createConveyorBelt();

#endif /* !ICONVEYORBELT_HPP_ */
