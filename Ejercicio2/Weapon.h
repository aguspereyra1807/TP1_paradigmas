#pragma once
#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Weapon { // Interfaz
    public:
        Weapon(double power, double damage)
            : magicPower(power), physicalDamage(damage) {}
        virtual double getDamage(float enemyPhysicalResistance, float enemyMagicResistance) = 0;

        virtual ~Weapon();

    protected:
        const double magicPower;
        const double physicalDamage;
        static string type;
};