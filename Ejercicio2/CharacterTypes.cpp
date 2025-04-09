#include "CharacterTypes.h"

using namespace std;

string Mage::type = "Mage";

Mage::Mage(double mResistance, double pResistance, int knowledge)
    :   magicResistance(mResistance),
        physicalResistance(pResistance),
        magicKnowledge(knowledge) {}

string Warrior::type = "Warrior";

Warrior::Warrior(double mResistance, double pResistance, int state)
    :   magicResistance(mResistance),
        physicalResistance(pResistance),
        physicState(state) {}
