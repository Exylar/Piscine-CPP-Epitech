/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Wrap
*/

#ifndef WRAP_HPP_
#define WRAP_HPP_

#include "Object.hpp"

class Wrap : public Object
{
    protected:
        bool isOpened;
        Object *content;

	public:
		Wrap(const std::string &wrapTitle);
		virtual ~Wrap();

        void isTaken() const final;
        bool canWrap() const final;

        Object *getContent();

        virtual bool wrapMeThat(Object *object) = 0;
        virtual void openMe() = 0;
        virtual void closeMe() = 0;
};

#endif /* !WRAP_HPP_ */
