/*
** EPITECH PROJECT, 2020
** cpp_d14a_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef WATER_RECLAIMER_HPP_
#define WATER_RECLAIMER_HPP_

#include <cstddef>
#include "BaseComponent.hpp"

class WaterReclaimer : public BaseComponent
{
    public:
        WaterReclaimer();
        virtual ~WaterReclaimer() {}

        void start();
        void generateWater();
        void useWater(int water);
    private:
        int _water;
        bool _started;
};

#endif // WATER_RECLAIMER_HPP_
