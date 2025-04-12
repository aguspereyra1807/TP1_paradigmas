#include "characterFactory.h"


float CharacterFactory::randfloat(float min, float max) {
    return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max - min);
}

int CharacterFactory::randint(int min, int max) {
    srand(static_cast<unsigned int>(time(0)));
    return min + (rand() % max - min + 1);
} 

bool CharacterFactory::randbool() {
    if (randint(0,1) == 0) return false;
    return true;
}

int CharacterFactory::characterAmount() {
    return randint(3,7);
}

int CharacterFactory::weaponAmount() {
    return randint(0,2);
}

unique_ptr<Weapon> CharacterFactory::makeWeapon(int weaponType, double damage) {
    if (weaponType > 8 || weaponType < 0) {
        cerr << "Índice fuera de rango" << endl;
        return nullptr;
    }

    WEAPON weaponClass = static_cast<WEAPON>(weaponType);

    switch (weaponClass) {

        case WEAPON::Potion: {

            int level = randint(0, 5);
            set<string> effects = {"Poisoning"};
            int duration = randint(0, 60);
            float intensity = randfloat(0.0, 1.0);
            int uses = randint(0, 10);
            return make_unique<Potion>(damage, level, effects, duration, intensity, uses);

        }
        
        case WEAPON::SpellsBook: {

            int level = randint(0, 5);
            MAGIC_T type = static_cast<MAGIC_T>(randint(0,2));
            int pages = randint(30,600);
            string language = "Latin";
            return make_unique<SpellsBook>(damage, level, type, pages, language);

        }

        case WEAPON::Amulet: {

            int level = randint(0,5);
            MATERIAL_T material = static_cast<MATERIAL_T>(randint(0,2));
            MAGIC_T magicType = static_cast<MAGIC_T>(randint(0,2));
            int rarity = randint(0,10);
            EFFECT_T effect = static_cast<EFFECT_T>(randint(0,2));
            return make_unique<Amulet>(damage, level, material, magicType, rarity, effect);

        }

        case WEAPON::Cane: {

            int level = randint(0,5);
            MATERIAL_T material = static_cast<MATERIAL_T>(randint(0,2));
            EFFECT_T effect = static_cast<EFFECT_T>(randint(0,2));
            int length = randint(20,150);
            float hardness = randfloat(0.0,1.0);
            return make_unique<Cane>(damage, level, material, effect, length, hardness);

        }

        case WEAPON::SimpleAxe: {
            
            float criticChance = randfloat(0.0,1.0);
            bool state = randbool();
            float weight = randfloat(1,10);
            MATERIAL_T material = static_cast<MATERIAL_T>(randint(0,2));
            return make_unique<SimpleAxe>(damage, criticChance, state, weight, material);

        }

        case WEAPON::DoubleAxe: {

            float criticChance = randfloat(0.0,1.0);
            bool state = randbool();
            float doubleChance = randfloat(0.0,1.0);
            int sharpness = randint(1,10);
            return make_unique<DoubleAxe>(damage, criticChance, state, doubleChance, sharpness);

        }

        case WEAPON::Sword: {

            float criticChance = randfloat(0.0,1.0);
            bool broken = randbool();
            QUALITY quality = static_cast<QUALITY>(randint(0,4));
            float accuracy = randfloat(0.0,1.0);
            return make_unique<Sword>(damage, criticChance, broken, quality, accuracy);

        }

        case WEAPON::Spear: {

            float criticChance = randfloat(0.0,1.0);
            int reach = randint(1,10);
            float sharpness =  randfloat(1.0,2.0);
            MATERIAL_T material = static_cast<MATERIAL_T>(randint(0,2));
            return make_unique<Spear>(damage, criticChance, reach, sharpness, material);
        
        }

        case WEAPON::Club: {

            float weight = randfloat(1.0, 7.0);
            bool spykes = randbool();
            MATERIAL_T material = static_cast<MATERIAL_T>(randint(0,2));
            return make_unique<Club>(damage, weight, spykes, material);


        }
    }
    return nullptr;
}

unique_ptr<Character> CharacterFactory::makeCharacter(int characterType, double health, float resistance, int weaponAmount) {
    
    bool isMage = false;

    if (characterType > 8 || characterType < 0) {
        cerr << "Índice fuera de rango" << endl;
        return nullptr;
    }
    else if (characterType >= 4) isMage = true;

    vector<unique_ptr<Weapon>> weaponList;

    for (int i = 0; i < weaponAmount; ++i) {
        int weaponType;
        if (isMage)  weaponType = randint(0,3);
        else weaponType = randint(4,8);

        double baseDamage = static_cast<double>(randint(1,10));
        unique_ptr<Weapon> weapon = makeWeapon(weaponType, baseDamage);

        weaponList.push_back(move(weapon));
    }

    CHARACTER characterClass = static_cast<CHARACTER>(characterType);

    switch(characterClass) {

        case CHARACTER::Sorcerer: {

            ELEMENT_T element = static_cast<ELEMENT_T>(randint(0,5));
            return make_unique<Sorcerer>(health, resistance, move(weaponList), element);

        }

        case CHARACTER::Conjurer: {

            return make_unique<Conjurer>(health, resistance, move(weaponList));
            
        }

        case CHARACTER::Wizard: {
            
            return make_unique<Wizard>(health, resistance, move(weaponList));

        }

        case CHARACTER::Necromancer: {
            
            int souls = randint(1, 5);
            return make_unique<Necromancer>(health, resistance, move(weaponList), souls);

        }

        case CHARACTER::Barbarian: {
            
            float musclePercentage = randfloat(1.0,2.0);
            return make_unique<Barbarian>(health, resistance, move(weaponList), musclePercentage);
            
        }
        
        case CHARACTER::Paladin: {
            
            GOD invoquedBy = static_cast<GOD>(randint(0,3));
            return make_unique<Paladin>(health, resistance, move(weaponList), invoquedBy);
        }

        case CHARACTER::Knight: {

            REGION region = static_cast<REGION>(randint(0,3));
            return make_unique<Knight>(health, resistance, move(weaponList), region);
        }

        case CHARACTER::Mercenary: {

            int jobsDone = randint(1,10);
            double price = static_cast<double>(randfloat(10.0,100.0));
            return make_unique<Mercenary>(health, resistance, move(weaponList), jobsDone, price);

        }

        case CHARACTER::Gladiator: {

            int championAmount = randint(1,5);
            return make_unique<Gladiator>(health, resistance, move(weaponList), championAmount);

        }
    }
    return nullptr;
}