#pragma once
#include "CharacterTypes.h"

enum class REGION {North, South, East, West};
enum class GOD {Tyr, Baldr, Thor, Loki};

class Barbarian: public Warrior {
    public:
        Barbarian(double health, float resistance, vector<unique_ptr<Weapon>> weapons, int stamina, float muscle);
        void train(); // + musclePercentage
    private:
        float musclePercentage;
};

class Paladin: public Warrior {
    public:
        Paladin(double health, float resistance, vector<unique_ptr<Weapon>> weapons, int stamina, GOD god);
        GOD invoquedBy() const;
    private:
        const GOD servingTo;
};

class Knight: public Warrior {
    public:
        Knight(double health, float resistance, vector<unique_ptr<Weapon>> weapons, int stamina, REGION zone);
        REGION getGuardingZone() const;
        void horseRide(); // +speed
    private:
        const REGION guardingZone;
        int speed;
};

class Mercenary: public Warrior {
    public:
        Mercenary(double health, float resistance, vector<unique_ptr<Weapon>> weapons, int stamina, int jobs, double price);
        
    private:
        const int jobsDone;
        const int priceForJob;
        double money;
         
        double calculateMoney() const;
};

class Gladiator: public Warrior {
    public:
        Gladiator(double health, float resistance, vector<unique_ptr<Weapon>> weapons, int stamina, int championAmount);
        int getChampionCounter() const;
        void winChampionship();
    private:
        int championCounter;
};