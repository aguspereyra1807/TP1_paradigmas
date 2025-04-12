#pragma once
#include "MageTypes.h"
#include "WarriorTypes.h"
#include "MagicItems.h"
#include "CombatWeapons.h"
#include <cstdlib>
#include <ctime>

enum class CHARACTER {Sorcerer, Conjurer, Wizard, Necromancer, Barbarian, Paladin, Knight, Mercenary, Gladiator}; 
enum class WEAPON {Potion, SpellsBook, Amulet, Cane, SimpleAxe, DoubleAxe, Sword, Spear, Club};

class CharacterFactory {
    public:
        static unique_ptr<Character> makeCharacter(double health, float resistance, int weaponAmount);
    private:
        static unique_ptr<Weapon> makeWeapon(int weaponType, double damage);
        
        static int randint(int min, int max);
        static float randfloat(float min, float max);
        static bool randbool();
        static int weaponAmount();
        static int characterAmount();
};