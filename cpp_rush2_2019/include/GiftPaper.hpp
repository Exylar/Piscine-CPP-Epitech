/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** GiftPaper
*/

#ifndef GIFTPAPER_HPP_
#define GIFTPAPER_HPP_

#include "Wrap.hpp"

class GiftPaper : public Wrap
{
	public:
		GiftPaper();
		~GiftPaper();

        Object *clone() const final;

		bool wrapMeThat(Object *object) final;
		void openMe() final;
		void closeMe() final;
};

#endif /* !GIFTPAPER_HPP_ */
