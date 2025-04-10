#include "MageTypes.h"
#include <iostream>

// Sorcerer

Sorcerer::Sorcerer(double health, float resistance, string name, vector<shared_ptr<MagicItem>> weapons, ELEMENT_T elem)
    :   Mage(health, resistance, "Sorcerer", weapons), elementType(elem) {
}

ELEMENT_T Sorcerer::getElementType() const {
    return elementType;
}

// Conjurer

Conjurer::Conjurer(double health, float resistance, string name, vector<shared_ptr<MagicItem>> weapons) 
    :   Mage(health, resistance, "Sorcerer", weapons) {
    summonedCreatures = vector<string>();
    summonCreature("Cyclop");
    summonCreature("Wraith");
    summonCreature("Skeleton");
}

void Conjurer::summonCreature(string creature) {
    summonedCreatures.push_back(creature);
}

void Conjurer::showSummonedCreatures() const {
    for (auto creature : summonedCreatures) {
        cout << " - " << creature << endl;
    }
}

// Wizard

Wizard::Wizard(double health, float resistance, string name, vector<shared_ptr<MagicItem>> weapons) 
    :   Mage(health, resistance, "Wizard", weapons) {
    potions = vector<string>();
    makePotion("Essence of Fury");
    makePotion("Venomous Ichor");
    makePotion("Essence of Chronos");
}

void Wizard::makePotion(string newPotion) {
    potions.push_back(newPotion);
}

void Wizard::showPotions() const {
    for (auto potion : potions) {
        cout << " - " << potion << endl;
    }
}

// Necromancer

Necromancer::Necromancer(double health, float resistance, string name, vector<shared_ptr<MagicItem>> weapons, int souls)
    :   Mage(health, resistance, "Wizard", weapons), soulsStealed(souls) {
}

int Necromancer::getSoulStealedAmount() const {
    return soulsStealed;
}