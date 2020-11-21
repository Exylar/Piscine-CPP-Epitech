/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D08_2019_DROIDMEMORY_HPP
#define CPP_D08_2019_DROIDMEMORY_HPP

#include <iostream>

class DroidMemory {
    public:
        DroidMemory();
        ~DroidMemory();
        void setFingerprint(size_t fingerprint);
        void setExp(size_t exp);
        size_t getFingerprint() const;
        size_t getExp() const;
        DroidMemory &operator<<(DroidMemory &droidMemory);
        DroidMemory &operator>>(DroidMemory &droidMemory);
        DroidMemory &operator+=(DroidMemory &droidMemory);
        DroidMemory &operator+=(size_t xp);
        DroidMemory &operator+(DroidMemory &droidMemory);
        DroidMemory &operator+(size_t xp);
    private:
        size_t _Fingerprint = 0;
        size_t  _Exp = 0;
};

std::ostream &operator<<(std::ostream &out, const DroidMemory &droidMemory);

#endif //CPP_D08_2019_DROIDMEMORY_HPP
