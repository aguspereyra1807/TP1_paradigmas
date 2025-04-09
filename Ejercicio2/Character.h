#pragma once

class Character {
    virtual int getHP() const = 0;
    virtual void receiveDamage(double damage) = 0;
};