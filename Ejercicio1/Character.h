#pragma once
#include <vector>
#include <utility>
#include <string>

using namespace std;

class Character {
    public:
        virtual double getHP() const = 0;
        virtual double receiveDamage(double damage) = 0;

        virtual float getResistance() const = 0;
        virtual pair<string, double> doDamage(float enemyResistance) const = 0; // weaponType, damageToDo

        virtual ~Character() = default;
};