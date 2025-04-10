#include "WeaponTypes.h"


// Magic Item

MagicItem::MagicItem(double power, int level, const string name): magicPower(power), magicLevel(level), type(name) {}

// getDamage default
double MagicItem::getDamage(float enemyPhysicalResistance, float enemyMagicResistance) {
    return magicPower*enemyMagicResistance;
}

string MagicItem::getType() const {
    return type;
}

// Combat Weapon

CombatWeapon::CombatWeapon(double damage, float critic, const string name): physicalDamage(damage), criticChance(critic), type(name) {}

double CombatWeapon::getDamage(float enemyPhysicalResistance, float enemyMagicResistance) {
    return physicalDamage*enemyPhysicalResistance*criticChance;
}

string CombatWeapon::getType() const {
    return type;
}