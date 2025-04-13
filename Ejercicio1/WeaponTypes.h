#pragma once

#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Weapon.h"

enum class MATERIAL_T {Wood, Steel, Diamond};
class MagicItem: public Weapon { // Clase Abstracta
    public:
        MagicItem(double power, int level, const string name);
        ~MagicItem();
        virtual double getDamage(float enemyResistance) override;
        virtual string getType() const override;

    protected: 
        const double magicPower;
        const int magicLevel;
        const string type;
};

class CombatWeapon: public Weapon { // Clase Abstracta
    public:
        CombatWeapon(double damage, float critic, const string name);
        ~CombatWeapon();
        virtual double getDamage(float enemyResistance) override;
        virtual string getType() const override;
        
    protected:
        const double physicalDamage;
        const float criticChance = 0.0;
        const string type;

        bool isCritic() const;
};