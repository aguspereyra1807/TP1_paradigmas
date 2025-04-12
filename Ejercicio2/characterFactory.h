#pragma once
#include "../Ejercicio1/MageTypes.h"
#include "../Ejercicio1/WarriorTypes.h"
#include "../Ejercicio1/MagicItems.h"
#include "../Ejercicio1/CombatWeapons.h"
#include <cstdlib>
#include <ctime>

enum class CHARACTER {Sorcerer, Conjurer, Wizard, Necromancer, Barbarian, Paladin, Knight, Mercenary, Gladiator}; 
enum class WEAPON {Potion, SpellsBook, Amulet, Cane, SimpleAxe, DoubleAxe, Sword, Spear, Club};

class CharacterFactory {
    public:
        static unique_ptr<Character> makeCharacter(int characterType, double health, float resistance, int weaponAmount);
        static int randint(int min, int max);
        static float randfloat(float min, float max);
    
        private:
        static unique_ptr<Weapon> makeWeapon(int weaponType, double damage);
        
        static bool randbool();
        static int weaponAmount();
        static int characterAmount();

};
