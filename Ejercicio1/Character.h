#pragma once
#include <vector>

class Character {
    virtual double getHP() const = 0;
    virtual double receiveDamage(double damage) = 0;
};