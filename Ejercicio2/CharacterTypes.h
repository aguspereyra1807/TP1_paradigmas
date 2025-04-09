#pragma once
#include "Character.h"

#include <string>

using namespace std;

class Mage: public Character {
    public:
        Mage(double mResistance, double pResistance, int knowledge);

        static string type;

    protected:
        const double magicResistance;
        const double physicalResistance;
        const int magicKnowledge; // 1-10
};

class Warrior: public Character {
    public:
        Warrior(double mResistance, double pResistance, int state);
        
        static string type;

    protected:
        const double magicResistance;
        const double physicalResistance;
        const int physicState;
}