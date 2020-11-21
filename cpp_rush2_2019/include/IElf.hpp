/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** IElf
*/

#ifndef IELF_HPP_
#define IELF_HPP_

#include "ITable.hpp"
#include "IConveyorBelt.hpp"
#include "Hand.hpp"

class IElf
{
    public:
        virtual ~IElf() {};

        virtual ITable *getTable() const = 0;
        virtual void setTable(ITable *) = 0;
        virtual IConveyorBelt *getConveyor() const = 0;
        virtual void setConveyor(IConveyorBelt *) = 0;
        virtual bool putOnTable() = 0;
        virtual bool putOnConveyor() = 0;
        virtual bool takeFromTable(unsigned int) = 0;
        virtual bool takeFromConveyor() = 0;
        virtual bool pressIn() = 0;
        virtual bool pressOut() = 0;
        virtual bool openWrap() = 0;
        virtual bool closeWrap() = 0;
        virtual bool wrapObjectFromHand(unsigned int) = 0;
        virtual bool wrapObjectToHand(unsigned int) = 0;
        virtual std::string **lookTheTable() const = 0;

        virtual bool wrapGift() = 0;
};

#endif /* !IELF_HPP_ */
