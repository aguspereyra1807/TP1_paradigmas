#pragma once
#include <vector>

class Character {
    public:
        virtual double getHP() const = 0;
        virtual double receiveDamage(double damage) = 0;
        virtual ~Character() = default;
};