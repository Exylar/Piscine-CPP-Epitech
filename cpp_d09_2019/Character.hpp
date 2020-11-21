/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D09_2019_CHARACTER_HPP
#define CPP_D09_2019_CHARACTER_HPP

#include <iostream>

class Character {

    public:
        typedef enum Range {
            CLOSE,
            RANGE,
        } AttackRange;
        Character(const std::string &name, int level);
        ~Character();
        const std::string &getName() const;
        int getLvl() const;
        int getPv() const;
        int getPower() const;
        AttackRange getRange() const;
        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
        void TakeDamage(int damage);
        AttackRange Range = CLOSE;
    protected:
        std::string _name = "Kreog";
        int _level = 1;
        int _health = 100;
        int _power = 100;
        std::string _class = "Character";
        std::string _race = "Human";
        int _strength = 5;
        int _stamina = 5;
        int _intelligence = 5;
        int _spirit = 5;
        int _agility= 5;
};

/*
class Kreog : public Character {
    public:

    private:


}; */


#endif //CPP_D09_2019_CHARACTER_HPP
