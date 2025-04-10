#include "CombatWeapons.h"

// Simple Axe

SimpleAxe::SimpleAxe(double damage, float critic, bool state, float weight, MATERIAL_T material)
    :   CombatWeapon(damage, critic, "Simple Axe"), weight(weight), material(material) {
        state = state;
}

double SimpleAxe::getDamage(float enemyPhysicalResistance, float enemyMagicResistance) {
    float discount = 1, x = 1.0;
    if (isRusty()) discount = 0.7;
    if (isCritic()) x = 1.75;
    return physicalDamage*discount*x*(1-enemyPhysicalResistance);
}

bool SimpleAxe::isRusty() const {
    if (!state) return true;
    return false;
}

void SimpleAxe::clean() {
    state = true;
}

float SimpleAxe::getWeight() const {
    return weight;
}

MATERIAL_T SimpleAxe::getMaterial() const {
    return material;
}

// DoubleAxe

DoubleAxe::DoubleAxe(double damage, float critic, bool state, float doubleChance, int sharpness)
    :   CombatWeapon(damage, critic, "Double Axe"), doubleHitChance(doubleChance), sharpness(sharpness) {
        state = state;
}

double DoubleAxe::getDamage(float enemyPhysicalResistance, float enemyMagicResistance) {
    float discount = 1, x = 1.0, y = 1.0;
    if (isRusty()) discount = 0.7;
    if (isCritic()) x = 1.75;
    if (isDoubleHit()) y = 1.5;
    return physicalDamage*discount*x*y*(1-enemyPhysicalResistance);
}

bool DoubleAxe::isRusty() const {
    if (!state) return true;
    return false;
}

void DoubleAxe::clean() {
    state = true;
}

bool DoubleAxe::isDoubleHit() const {
    return static_cast<float>(rand()) / RAND_MAX >= doubleHitChance;
}

int DoubleAxe::getSharpness() const {
    return sharpness;
}

// Spear

Spear::Spear(double damage, float critic, int reach, float sharpness, MATERIAL_T material)
    :   CombatWeapon(damage, critic, "Spear"), reach(reach), sharpness(sharpness), material(material) {
}

double Spear::getDamage(float enemyPhysicalResistance, float enemyMagicResistance) {
    if (isCritic()) return physicalDamage*sharpness*(pierceLevel / 5)*(1-enemyPhysicalResistance)* 1.75;
    else return physicalDamage*sharpness*(pierceLevel / 5)*(1-enemyPhysicalResistance);
}

int Spear::getReach() const {
    return reach;
}

float Spear::getSharpness() const {
    return sharpness;
}

MATERIAL_T Spear::getMaterial() const {
    return material;
}

void Spear::reinforceTip() {
    pierceLevel++;
}
