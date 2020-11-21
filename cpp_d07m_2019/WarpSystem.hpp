/*
** EPITECH PROJECT, 2019
** cpp_d07m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D07M_2019_WARPSYSTEM_HPP
#define CPP_D07M_2019_WARPSYSTEM_HPP

#include <iostream>

namespace WarpSystem {
    class QuantumReactor {
        public:
            QuantumReactor();
            bool isStable();
            void setStability(bool stability);
            QuantumReactor *checkReactor();
        private:
            bool _stability = true;
    };

    class Core {
        public:
            Core(QuantumReactor *quantumReactor);
            QuantumReactor *_coreReactor;
    };
}

#endif //CPP_D07M_2019_WARPSYSTEM_HPP
