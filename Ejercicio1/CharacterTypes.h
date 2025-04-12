#pragma once
#include "Character.h"
#include "WeaponTypes.h"

#include <string>

using namespace std;

class Mage: public Character {
    public:
        Mage(double health, float resistance, string name, vector<unique_ptr<Weapon>> weapons);
        virtual double receiveDamage(double damage) override;
        virtual float getResistance() const override;
        virtual pair<string, double> doDamage(double enemyResistance) const override;
        double getHP() const override;
        
    protected:
        double hp;
        const float resistance;
        const string type;
        vector<unique_ptr<Weapon>> ownedWeapons;
};

class Warrior: public Character {
    public:
        Warrior(double health, float resistance, string name, vector<unique_ptr<Weapon>> weapons);
        virtual double receiveDamage(double damage);
        virtual float getResistance() const override;
        virtual pair<string, double> doDamage(double enemyResistance) const override;        
        double getHP() const override;

    protected:
        double hp;
        const float resistance;
        const string type;
        vector<unique_ptr<Weapon>> ownedWeapons;
};