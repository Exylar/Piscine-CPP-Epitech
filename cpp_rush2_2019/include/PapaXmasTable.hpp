/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** PapaXmasTable
*/

#ifndef PAPAXMASTABLE_HPP_
#define PAPAXMASTABLE_HPP_

#include "ITable.hpp"

#define NB_TOY 2
#define NB_BOX 2
#define NB_GIFT_PAPER 2

class PapaXmasTable : public ITable {
    public:
        PapaXmasTable();
        ~PapaXmasTable() override;

        void put(unsigned int idx, Object *&value) override;
        bool operator<<(Object *&) override; // put

        Object *operator[](unsigned int idx) const override;
        Object *take(unsigned int idx) override;
        operator size_t() const override;
        std::string **lookAtTheTable() const override;
    private:
        Object *_inventory[MaxSize];
};

#endif /* !PAPAXMASTABLE_HPP_ */
