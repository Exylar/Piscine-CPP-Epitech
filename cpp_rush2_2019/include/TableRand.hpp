/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TableRand
*/

#ifndef TABLERAND_HPP_
#define TABLERAND_HPP_

#include "ITable.hpp"

class TableRand : public ITable
{
    public:
       TableRand();
       ~TableRand();

        void put(unsigned int idx, Object *&value) final;
        bool operator<<(Object *&) final; // put

        Object *operator[](unsigned int idx) const final;
        Object *take(unsigned int idx) final;
        operator size_t() const final;
        std::string **lookAtTheTable() const final;
    private:
        Object *_inventory[MaxSize];
};

#endif /* !TABLERAND_HPP_ */
