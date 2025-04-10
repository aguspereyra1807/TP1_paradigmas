#pragma once

#include "WeaponTypes.h"

enum class QUALITY {FactoryNew, MinimalWear, FieldTested, WellWorn, BattleScarred};

class SimpleAxe: public CombatWeapon {
    public:
        SimpleAxe(double damage, float critic, bool state, float weight, MATERIAL_T material);

        double getDamage(float enemyResistance) override;

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

        double getDamage(float enemyResistance) override;

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
    public:
        Sword(double damage, float critic, bool broken, QUALITY quality, float accuracy);

        double getDamage(float enemyResistance) override;
        bool isBroken() const;
        QUALITY getQuality() const;
        float getAccuracy() const;

    private:
        bool broken;
        const QUALITY quality;
        const float accuracy;
};

class Spear: public CombatWeapon {
    public:
        Spear(double damage, float critic, int reach, float sharpness, MATERIAL_T material);

        double getDamage(float enemyResistance) override;    
    
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
    public:
        Club(double damage, float kg, bool hasSpykes, MATERIAL_T madeOf); // 0 critic

        double getDamage(float enemyResistance) override;
        bool hasSpykes() const;
        MATERIAL_T getMaterial() const;

    private:
        const float weight;
        const bool spykes;
        const MATERIAL_T material;
};