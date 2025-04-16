#include "CharacterTypes.h"

using namespace std;

// Mage

Mage::Mage(double health, float resistance, string name, vector<unique_ptr<Weapon>> weapons, int mana): resistance(resistance), type(name), ownedWeapons(std::move(weapons)), mana(mana) {
    hp = health;
}

// Recibe más daño
double Mage::receiveDamage(double damage) {
    if (damage > hp) {
        hp = 0;
        return damage;
    }
    hp -= damage;
    return damage;
}

double Mage::getHP() const {
    return hp;
}

float Mage::getResistance() const {
    return resistance;
}

pair<string, double> Mage::doDamage(float enemyResistance) const {
    if (ownedWeapons.empty()) return pair<string, double>("nothing", 0.0);

    int index = rand() % (ownedWeapons.size());

    return pair<string,double>(ownedWeapons[index].get()->getType(), ownedWeapons[index].get()->getDamage(enemyResistance));
}

int Mage::getMana() const {
    return mana;
}

// Warrios
Warrior::Warrior(double health, float resistance, string name, vector<unique_ptr<Weapon>> weapons, int stamina): resistance(resistance), type(name), ownedWeapons(std::move(weapons)), stamina(stamina) {
    hp = health;
}

double Warrior::receiveDamage(double damage) {
    if (damage > hp) {
        hp = 0;
        return damage;
    }
    hp -= damage;
    return damage;
}

double Warrior::getHP() const {
    return hp;
}

float Warrior::getResistance() const {
    return resistance;
}

pair<string, double> Warrior::doDamage(float enemyResistance) const {
    if (ownedWeapons.empty()) return pair<string, double>("nothing", 0.0);
    
    int index = rand() % (ownedWeapons.size());

    return pair<string,double>(ownedWeapons[index].get()->getType(), ownedWeapons[index].get()->getDamage(enemyResistance));
}

int Warrior::getStamina() const {
    return stamina;
}