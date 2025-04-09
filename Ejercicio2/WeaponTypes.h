#pragma once
#include "Weapon.h"

class MagicItem: public Weapon { // Clase Abstracta
    public:
        MagicItem(double power, int level);
        virtual double getDamage(float enemyPhysicalResistance, float enemyMagicResistance) override;

        static const string type;

    protected:
        const int magicLevel;
};

class CombatWeapon: public Weapon { // Clase Abstracta
    public:
        CombatWeapon(double damage, float critic);
        virtual double getDamage(float enemyPhysicalResistance, float enemyMagicResistance) override;
    
        static const string type;

    protected:
        const float criticChance = 1; // critic >= 1
};