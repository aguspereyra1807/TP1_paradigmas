#include "CharacterTypes.h"

using namespace std;

// Mage

Mage::Mage(double health, float resistance, string name, vector<unique_ptr<MagicItem>> weapons): resistance(resistance), type(name) {
    hp = health;
    ownedWeapons = weapons;
}

// Recibe más daño
double Mage::receiveDamage(double damage) {
    hp -= damage*1.10;
    return damage*1.10;
}

double Mage::getHP() const {
    return hp;
}

vector<unique_ptr<MagicItem>> Mage::getOwnedWeapons() const {
    return ownedWeapons;
}

// Warrios
Warrior::Warrior(double health, float resistance, string name, vector<unique_ptr<CombatWeapon>> weapons): resistance(resistance), type(name) {
    hp = health;
    ownedWeapons = weapons;
}

double Warrior::receiveDamage(double damage) {
    hp -= damage*0.90;
    return damage*0.90;
}

double Warrior::getHP() const {
    return hp;
}

vector<unique_ptr<MagicItem>> Mage::getOwnedWeapons() const {
    return ownedWeapons;
}