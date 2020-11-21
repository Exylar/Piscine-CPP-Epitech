/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** PapaXmasElf
*/

#ifndef PAPAXMASELF_HPP_
#define PAPAXMASELF_HPP_

#include "IElf.hpp"
#include "Hand.hpp"

class PapaXmasElf : public IElf
{
    public:
       PapaXmasElf(ITable *table = nullptr, IConveyorBelt *conveyor = nullptr);
       ~PapaXmasElf();

        ITable *getTable() const final;
        void setTable(ITable *) final;
        IConveyorBelt *getConveyor() const final;
        void setConveyor(IConveyorBelt *) final;
        bool putOnTable() final;
        bool putOnConveyor() final;
        bool takeFromTable(unsigned int) final;
        bool takeFromConveyor() final;
        bool pressIn() final;
        bool pressOut() final;
        bool openWrap() final;
        bool closeWrap() final;
        bool wrapObjectFromHand(unsigned int idx) final;
        bool wrapObjectToHand(unsigned int idx) final;
        std::string **lookTheTable() const final;

        bool wrapGift() final;

    private:
        Hand _hand;
        ITable *_table;
        IConveyorBelt *_conveyor;

        unsigned int findPaper(std::string **names);
        unsigned int findBox(std::string **names);
        unsigned int findToy(std::string **names);
        bool sendToConveyor(unsigned int toyIdx, unsigned int boxIdx, unsigned int paperIdx);
        bool getFromConveyor();
};

#endif /* !PAPAXMASELF_HPP_ */
