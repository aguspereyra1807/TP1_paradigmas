#pragma once
#include "CharacterTypes.h"

enum class ELEMENT_T {Fire, Ice, Electricity, Water, Air, Ground};

class Sorcerer: public Mage {
    public:
        Sorcerer(double health, float resistance, vector<unique_ptr<MagicItem>> weapons, ELEMENT_T elem);
        ELEMENT_T getElementType() const;
    private:
        const ELEMENT_T elementType;
};

class Conjurer: public Mage {
    public:
        Conjurer(double health, float resistance, vector<unique_ptr<MagicItem>> weapons);
        void summonCreature(string creature);
        void showSummonedCreatures() const;
    private:
        vector<string> summonedCreatures;
};

class Wizard: public Mage {
    public:
        Wizard(double health, float resistance, vector<unique_ptr<MagicItem>> weapons);
        void makePotion(string newPotion);
        void showPotions() const;
    private:
        vector<string> potions;
};

class Necromancer: public Mage {
    public:
        Necromancer(double health, float resistance, vector<unique_ptr<MagicItem>> weapons, int souls);
        int getSoulStealedAmount() const;
    private:
        const int soulsStealed;
};
