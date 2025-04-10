#pragma once

#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Weapon.h"

class MagicItem: public Weapon { // Clase Abstracta
    public:
        MagicItem(double power, int level, const string name);
        virtual double getDamage(float enemyPhysicalResistance, float enemyMagicResistance) override;
        
        protected:
        const string type;
        const int magicLevel;
        const double magicPower;
};

class CombatWeapon: public Weapon { // Clase Abstracta
    public:
        CombatWeapon(double damage, float critic, const string name);
        virtual double getDamage(float enemyPhysicalResistance, float enemyMagicResistance) override;

    protected:
        const string type;
        const float criticChance = 0.0;
        const double physicalDamage;
};