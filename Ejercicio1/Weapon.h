#pragma once
#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Weapon { // Interfaz
    public:
        virtual double getDamage(float enemyResistance) = 0;
        virtual string getType() const = 0;
        virtual ~Weapon();
};