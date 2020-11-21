/*
** EPITECH PROJECT, 2019
** cpp_d07m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D07M_2019_BORG_HPP
#define CPP_D07M_2019_BORG_HPP

#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg {
    class Ship {
        public:
            Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield();
            void setShield(int shield);
            int getTorpedo();
            void setTorpedo(int torpedo);
        private:
            int _side;
            short _maxWarp;
            int _shield;
            int _photonTorpedo;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home = UNICOMPLEX;
    };
}

#endif //CPP_D07M_2019_BORG_HPP
