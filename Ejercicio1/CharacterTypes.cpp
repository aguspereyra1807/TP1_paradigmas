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

float Mage::getResistance() const {
    return resistance;
}

pair<string, double> Mage::doDamage(double enemyResistance) const {
    if (ownedWeapons.empty()) return pair<string, double>("", 0.0);

    int index = rand() % (ownedWeapons.size());

    return pair<string,double>(ownedWeapons[index].get()->getType(), ownedWeapons[index].get()->getDamage(enemyResistance));
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

float Warrior::getResistance() const {
    return resistance;
}

pair<string, double> Warrior::doDamage(double enemyResistance) const {
    if (ownedWeapons.empty()) return pair<string, double>("", 0.0);
    
    int index = rand() % (ownedWeapons.size());

    return pair<string,double>(ownedWeapons[index].get()->getType(), ownedWeapons[index].get()->getDamage(enemyResistance));
}