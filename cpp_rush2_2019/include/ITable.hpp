/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** ITable
*/

#ifndef ITABLE_HPP_
#define ITABLE_HPP_

#include "Object.hpp"

class ITable
{
    public:
        virtual ~ITable() {}

        static const unsigned int MaxSize = 10;

        virtual void put(unsigned int idx, Object *&value) = 0;
        virtual bool operator<<(Object *&) = 0; // put

        virtual Object *operator[](unsigned int idx) const = 0;
        virtual Object *take(unsigned int idx) = 0;
        virtual operator size_t() const = 0;
        virtual std::string **lookAtTheTable() const = 0;
};

ITable *createTable();

#endif /* !ITABLE_HPP_ */
