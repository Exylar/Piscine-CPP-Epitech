/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D10_2019_ISQUAD_HPP
#define CPP_D10_2019_ISQUAD_HPP

class ISquad {
    public:
        virtual ~ISquad() {}
        virtual int getCount() const = 0;
        virtual ISpaceMarine* getUnit(int) = 0;
        virtual int push(ISpaceMarine*) = 0;
};

#endif //CPP_D10_2019_ISQUAD_HPP
