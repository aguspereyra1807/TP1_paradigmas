#include "WarriorTypes.h"

// Barbarian

Barbarian::Barbarian(double health, float resistance, vector<shared_ptr<CombatWeapon>> weapons, float muscle)
    : Warrior(health, resistance, "Barbarian", weapons) {
    musclePercentage = muscle;
}

void Barbarian::train() {
    musclePercentage += 0.5;
}

// Paladin

Paladin::Paladin(double health, float resistance, vector<shared_ptr<CombatWeapon>> weapons, GOD god)
    :   Warrior(health, resistance, "Paladin", weapons), servingTo(god) {
}

GOD Paladin::invoquedBy() const {
    return servingTo;
}

// Knight

Knight::Knight(double health, float resistance, vector<shared_ptr<CombatWeapon>> weapons, REGION zone)
    :   Warrior(health, resistance, "Knight", weapons), guardingZone(zone) {
    speed = 5; // km/h
}

REGION Knight::getGuardingZone() const {
    return guardingZone;
}

void Knight::horseRide() {
    speed *= 2;
}

// Mercenary

Mercenary::Mercenary(double health, float resistance, vector<shared_ptr<CombatWeapon>> weapons, int jobs, double price)
    :   Warrior(health, resistance, "Mercenary", weapons), jobsDone(jobs), priceForJob(price) {
    money = calculateMoney();
}

double Mercenary::calculateMoney() const {
    return jobsDone*priceForJob;
}

// Gladiator

Gladiator::Gladiator(double health, float resistance, vector<shared_ptr<CombatWeapon>> weapons, int championAmount)
    :   Warrior(health, resistance, "Gladiator", weapons) {
    championCounter = championAmount;
}


int Gladiator::getChampionCounter() const {
    return championCounter;
}

void Gladiator::winChampionship() {
    championCounter++;
}
