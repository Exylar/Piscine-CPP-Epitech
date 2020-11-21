/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** PapaXmasConveyorBelt
*/

#ifndef PAPAXMASCONVEYORBELT_HPP_
#define PAPAXMASCONVEYORBELT_HPP_

#include "IConveyorBelt.hpp"

class PapaXmasConveyorBelt : public IConveyorBelt {
    public:
        PapaXmasConveyorBelt();
        ~PapaXmasConveyorBelt() override;

        Object *take() override;
        void operator<<(Object *&obj) override; // put
        bool put(Object *&obj);


        bool in() override;
        bool out() override;

        bool isEmpty() const override;
    private:
        Object *obj;
};

#endif /* !PAPAXMASCONVEYORBELT_HPP_ */
