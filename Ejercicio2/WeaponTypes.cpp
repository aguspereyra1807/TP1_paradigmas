#include "WeaponTypes.h"

// Magic Item
const string MagicItem::type = "Magic Item";

MagicItem::MagicItem(double power, int level)
    : Weapon(power, 0), magicLevel(level) {}

// getDamage default
double MagicItem::getDamage(float enemyPhysicalResistance, float enemyMagicResistance) {
    return magicPower*enemyMagicResistance;
}

// Combat Weapon
const string CombatWeapon::type = "Combat Weapon";

CombatWeapon::CombatWeapon(double damage, float critic)
    : Weapon(0, damage), criticChance(critic) {}

double CombatWeapon::getDamage(float enemyPhysicalResistance, float enemyMagicResistance) {
    return physicalDamage*enemyPhysicalResistance*criticChance;
}