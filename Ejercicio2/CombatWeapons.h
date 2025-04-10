#pragma once

#include "WeaponTypes.h"

class SimpleAxe: public CombatWeapon {
    public:
        SimpleAxe(double damage, float critic, bool state, float weight, MATERIAL_T material);

        double getDamage(float enemyPhysicalResistance, float enemyMagicResistance) override;

        bool isRusty() const;
        void clean();
        float getWeight() const;
        MATERIAL_T getMaterial() const;

    private:
        bool state;
        const float weight;
        const MATERIAL_T material;

};

class DoubleAxe: public CombatWeapon {
    public:
        DoubleAxe(double damage, float critic, bool state, float doubleChance, int sharpness);

        double getDamage(float enemyPhysicalResistance, float enemyMagicResistance) override;

        bool isRusty() const;
        void clean();
        bool isDoubleHit() const;
        int getSharpness() const;

    private:
        bool state;
        const float doubleHitChance;
        const int sharpness;
};

class Sword: public CombatWeapon {

};

class Spear: public CombatWeapon {
    public:
        Spear(double damage, float critic, int reach, float sharpness, MATERIAL_T material);

        double getDamage(float enemyPhysicalResistance, float enemyMagicResistance) override;    
    
        int getReach() const;
        float getSharpness() const;
        MATERIAL_T getMaterial() const;
        void reinforceTip();
    
    private:
        const int reach;
        const float sharpness;
        const MATERIAL_T material;
        int pierceLevel = 1;

};

class Club: public CombatWeapon {

};