/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Object.hpp"

class Toy : public Object
{
	public:
        Toy(const std::string &title = "Toy");
		virtual ~Toy();

        bool canWrap() const override;
};

#endif /* !TOY_HPP_ */
