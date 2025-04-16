#include "characterFactory.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<unique_ptr<Character>> mages;
    vector<unique_ptr<Character>> warriors;

    int mageAmount = CharacterFactory::randint(3,7); 
    int warriorAmount = CharacterFactory::randint(3,7);

    for (int i = 0; i < mageAmount; ++i) {        
        vector<int> weaponTypes;
        int weaponAmount = CharacterFactory::randint(0,2);
        for (int j = 0; j < weaponAmount; ++j) {
            weaponTypes.push_back(CharacterFactory::randint(0,3));
        }
        auto mage = CharacterFactory::makeCharacter(CharacterFactory::randint(0,3), 100, 0.1, weaponTypes);
        mages.push_back(move(mage));
        cout << " - Mago creado correctamente con " << weaponAmount << " armas" << endl;
    }

    for (int i = 0; i < warriorAmount; ++i) {
        
        vector<int> weaponTypes;
        int weaponAmount = CharacterFactory::randint(0,2);
        for (int j = 0; j < weaponAmount; ++j) {
            weaponTypes.push_back(CharacterFactory::randint(4,8));
        }
        auto warrior = CharacterFactory::makeCharacter(CharacterFactory::randint(4,8), 100, 0.1, weaponTypes);
        warriors.push_back(move(warrior));
        cout << " - Guerrero creado correctamente con " << weaponAmount << " armas" << endl;
    }

    return 0;
}