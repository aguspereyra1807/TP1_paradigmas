#include "MageTypes.h"
#include <iostream>

// Sorcerer

Sorcerer::Sorcerer(double health, float resistance, vector<unique_ptr<Weapon>> weapons, int mana, ELEMENT_T elem)
    :   Mage(health, resistance, "Sorcerer", move(weapons), mana), elementType(elem) {
}

ELEMENT_T Sorcerer::getElementType() const {
    return elementType;
}

// Conjurer

Conjurer::Conjurer(double health, float resistance, vector<unique_ptr<Weapon>> weapons, int mana) 
    :   Mage(health, resistance, "Sorcerer", move(weapons), mana) {
    summonedCreatures = vector<string>();
    summonCreature("Cyclop");
    summonCreature("Wraith");
    summonCreature("Skeleton")  ;
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

Wizard::Wizard(double health, float resistance, vector<unique_ptr<Weapon>> weapons, int mana) 
    :   Mage(health, resistance, "Wizard", move(weapons), mana) {
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

Necromancer::Necromancer(double health, float resistance, vector<unique_ptr<Weapon>> weapons, int mana, int souls)
    :   Mage(health, resistance, "Wizard", move(weapons), mana), soulsStealed(souls) {
}

int Necromancer::getSoulStealedAmount() const {
    return soulsStealed;
}