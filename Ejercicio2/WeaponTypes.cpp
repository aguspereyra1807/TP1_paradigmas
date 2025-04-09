#include "WeaponTypes.h"

// Magic Item
const string MagicItem::type = "Magic Item";

MagicItem::MagicItem(double power, int level): magicPower(power), magicLevel(level) {}

// getDamage default
double MagicItem::getDamage(float enemyPhysicalResistance, float enemyMagicResistance) {
    return magicPower*enemyMagicResistance;
}

// Combat Weapon
const string CombatWeapon::type = "Combat Weapon";

CombatWeapon::CombatWeapon(double damage, float critic): physicalDamage(damage), criticChance(critic) {}

double CombatWeapon::getDamage(float enemyPhysicalResistance, float enemyMagicResistance) {
    return physicalDamage*enemyPhysicalResistance*criticChance;
}