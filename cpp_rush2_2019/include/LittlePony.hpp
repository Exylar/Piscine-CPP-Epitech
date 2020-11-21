/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** LittlePony
*/

#ifndef LITTLEPONY_HPP_
#define LITTLEPONY_HPP_

#include "Toy.hpp"

class LittlePony : public Toy
{
	public:
		LittlePony(const std::string &title = "LittlePony");
		~LittlePony();

        void isTaken() const final;

		Object *clone() const final;
};

#endif /* !LITTLEPONY_HPP_ */
