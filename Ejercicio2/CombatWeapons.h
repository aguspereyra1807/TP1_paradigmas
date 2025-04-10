#pragma once

#include "WeaponTypes.h"

class SimpleAxe: public CombatWeapon {

};

class DoubleAxe: public CombatWeapon {

};

class Sword: public CombatWeapon {

};

class Spear: public CombatWeapon {
    public:
        Spear();

        double getDamage(float enemyPhysicalResistance, float enemyMagicResistance) override;    
    
        int getRange() const;
    
    private:
        const int range;
        

};

class Cudgel: public CombatWeapon {

};