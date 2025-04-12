#include "WeaponTypes.h"

// Magic Item

MagicItem::MagicItem(double power, int level, const string name): magicPower(power), magicLevel(level), type(name) {}

// getDamage default
double MagicItem::getDamage(float enemyResistance) {
    return magicPower*(1-enemyResistance);
}

string MagicItem::getType() const {
    return type;
}

MagicItem::~MagicItem() {}

// Combat Weapon

CombatWeapon::CombatWeapon(double damage, float critic, const string name): physicalDamage(damage), criticChance(critic), type(name) {}

double CombatWeapon::getDamage(float enemyResistance) {
    return physicalDamage*(1-enemyResistance)*criticChance;
}

string CombatWeapon::getType() const {
    return type;
}

bool CombatWeapon::isCritic() const {
    return static_cast<float>(rand()) / RAND_MAX >= criticChance;
}

CombatWeapon::~CombatWeapon() {}