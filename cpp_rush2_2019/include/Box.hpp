/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_

#include "Wrap.hpp"

class Box : public Wrap
{
	public:
		Box();
		~Box();

		Object *clone() const final;

		bool wrapMeThat(Object *object) final;
		void openMe() final;
		void closeMe() final;
};

#endif /* !BOX_HPP_ */
