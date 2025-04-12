#pragma once
#include <vector>

class Character {
    public:
        virtual double getHP() const = 0;
        virtual double receiveDamage(double damage) = 0;

        virtual float getResistance() const = 0;
        virtual pair<string, double> doDamage(double enemyResistance) const = 0; // weaponType, damageToDo

        virtual ~Character() = default;
};