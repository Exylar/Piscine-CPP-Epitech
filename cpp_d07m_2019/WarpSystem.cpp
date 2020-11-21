/*
** EPITECH PROJECT, 2019
** cpp_d07m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor() : _stability(true) {}

WarpSystem::Core::Core(QuantumReactor *quantumReactor) : _coreReactor(quantumReactor) {}

bool WarpSystem::QuantumReactor::isStable()
{
    return (_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}

WarpSystem::QuantumReactor *WarpSystem::QuantumReactor::checkReactor()
{
    return this;
}