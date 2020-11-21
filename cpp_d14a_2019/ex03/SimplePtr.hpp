/*
** EPITECH PROJECT, 2019
** cpp_d14a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/


#ifndef SIMPLE_PTR_HPP_
#define SIMPLE_PTR_HPP_

#include "BaseComponent.hpp"

class SimplePtr
{
    public:
        explicit SimplePtr(BaseComponent *rawPtr);
        ~SimplePtr();
        BaseComponent *get() const;

    private:
        // Make the class non copyable
        SimplePtr(SimplePtr const &);
        SimplePtr &operator=(SimplePtr const &);

        BaseComponent *_rawPtr;
};

#endif // SIMPLE_PTR_HPP_
