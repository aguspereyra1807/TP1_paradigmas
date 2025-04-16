#include "WarriorTypes.h"

// Barbarian

Barbarian::Barbarian(double health, float resistance, vector<unique_ptr<Weapon>> weapons, int stamina, float muscle)
    : Warrior(health, resistance, "Barbarian", move(weapons), stamina) {
    musclePercentage = muscle;
}

void Barbarian::train() {
    musclePercentage += 0.5;
}

// Paladin

Paladin::Paladin(double health, float resistance, vector<unique_ptr<Weapon>> weapons, int stamina, GOD god)
    :   Warrior(health, resistance, "Paladin", move(weapons), stamina), servingTo(god) {
}

GOD Paladin::invoquedBy() const {
    return servingTo;
}

// Knight

Knight::Knight(double health, float resistance, vector<unique_ptr<Weapon>> weapons, int stamina, REGION zone)
    :   Warrior(health, resistance, "Knight", move(weapons), stamina), guardingZone(zone) {
    speed = 5; // km/h
}

REGION Knight::getGuardingZone() const {
    return guardingZone;
}

void Knight::horseRide() {
    speed *= 2;
}

// Mercenary

Mercenary::Mercenary(double health, float resistance, vector<unique_ptr<Weapon>> weapons, int stamina, int jobs, double price)
    :   Warrior(health, resistance, "Mercenary", move(weapons), stamina), jobsDone(jobs), priceForJob(price) {
    money = calculateMoney();
}

double Mercenary::calculateMoney() const {
    return jobsDone*priceForJob;
}

// Gladiator

Gladiator::Gladiator(double health, float resistance, vector<unique_ptr<Weapon>> weapons, int stamina, int championAmount)
    :   Warrior(health, resistance, "Gladiator", move(weapons), stamina) {
    championCounter = championAmount;
}


int Gladiator::getChampionCounter() const {
    return championCounter;
}

void Gladiator::winChampionship() {
    championCounter++;
}
