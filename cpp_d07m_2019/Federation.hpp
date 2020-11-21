/*
** EPITECH PROJECT, 2019
** cpp_d07m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D07M_2019_FEDERATION_HPP
#define CPP_D07M_2019_FEDERATION_HPP

#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation {
    namespace Starfleet {
        class Captain {
            public:
                Captain(std::string name);
                int getAge();
                void setAge(int age);
                std::string getName();
            private:
                std::string _name;
                int _age;
        };

        class Ensign {
            public:
                Ensign(std::string name);
            private:
                std::string _name;
        };

        class Ship {
            public:
                Ship();
                Ship(int length, int width, std::string name, short maxWarp);
                void setupCore(WarpSystem::Core *core);
                void checkCore();
                void promote(Federation::Starfleet::Captain *captaine);
                bool move(int warp, Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();
                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
            private:
                int _length = 289;
                int _width = 132;
                std::string _name = "NULL";
                short _maxWarp = 6;
                int _shield = 100;
                int _photonTorpedo = 0;
                WarpSystem::Core *_core;
                Starfleet::Captain *_captaine;
                Destination _location = EARTH;
                Destination _home = EARTH;
        };
    }

    class Ship {
    public:
        Ship(int length, int width, std::string name);
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
        WarpSystem::Core *_core;
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        int _shield;
        int _photonTorpedo;
        Destination _location;
        Destination _home = VULCAN;
    };

}

#endif //CPP_D07M_2019_FEDERATION_HPP
