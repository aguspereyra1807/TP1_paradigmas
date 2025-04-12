#pragma once
#include "Character.h"
#include "WeaponTypes.h"

#include <string>

using namespace std;

class Mage: public Character {
    public:
        Mage(double health, float resistance, string name, vector<unique_ptr<MagicItem>> weapons);
        virtual double receiveDamage(double damage) override;

        virtual float getResistance() const override;
        virtual pair<string, double> doDamage(double enemyResistance) const override;

        double getHP() const override;
        vector<unique_ptr<MagicItem>> getOwnedWeapons() const;
        
    protected:
        double hp;
        const float resistance;
        const string type;
        vector<unique_ptr<MagicItem>> ownedWeapons;
};

class Warrior: public Character {
    public:
        Warrior(double health, float resistance, string name, vector<unique_ptr<CombatWeapon>> weapons);
        virtual double receiveDamage(double damage);

        virtual float getResistance() const override;
        virtual pair<string, double> doDamage(double enemyResistance) const override;
        
        double getHP() const override;
        vector<unique_ptr<CombatWeapon>> getOwnedWeapons() const;

    protected:
        double hp;
        const float resistance;
        const string type;
        vector<unique_ptr<CombatWeapon>> ownedWeapons;
};