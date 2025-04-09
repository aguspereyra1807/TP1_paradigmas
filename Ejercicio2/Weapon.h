#pragma once
#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Weapon { // Interfaz
    public:
        virtual double getDamage(float enemyPhysicalResistance, float enemyMagicResistance) = 0;
        virtual ~Weapon();
};