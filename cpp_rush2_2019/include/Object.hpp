/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include <string>

class Object
{
    private:
        const std::string title;

	public:
        Object(const std::string &title);
		virtual ~Object();

        const std::string &getTitle() const;
        virtual bool canWrap() const = 0;
        virtual void isTaken() const = 0;

        virtual Object *clone() const = 0;
};

#endif /* !OBJECT_HPP_ */
