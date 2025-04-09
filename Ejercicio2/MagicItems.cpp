#include "MagicItems.h"

// Potion

Potion::Potion(
    double power, 
    int level, 
    set<string> effects, 
    int duration, 
    float intensity, 
    int uses)
    : MagicItem(power, level), duration(duration), effectsIntensity(intensity) {
        effectsList = effects; 
        usesLeft = uses;
        effectiveness = calculateEffectiveness();
    }

double Potion::getDamage(float enemyPhysicalResistance, float enemyMagicResistance) {
    if (usesLeft > 0) {
        usesLeft--;
        return magicPower*enemyMagicResistance*effectiveness;
    }
    else {
        cout << "No quedan más usos de la poción" << endl;
        return 0;
    }
}

void Potion::showEffects() const {
    for (string eff : effectsList) {
        cout << "- " << eff << endl;
    }
}

void Potion::addEffect(string effect) {
    effectsList.insert(effect);
    return;
}

int Potion::getDuration() const {
    return duration;
}

float Potion::getIntensity() const {
    return effectsIntensity;
}

int Potion::getUsesLeft() const {
    return usesLeft;
}

// Devuelve un puntero a una nueva poción en base a las 2 dadas.
// Comina tanto los efectos como las estadísticas.
unique_ptr<Potion> Potion::operator+(Potion& other) const {
    auto mixedEffects = this->effectsList;
    mixedEffects.insert(other.effectsList.begin(), other.effectsList.end());

    return make_unique<Potion>(
        this->magicPower + other.magicPower,
        this->magicLevel + other.magicLevel,
        mixedEffects,
        (this->duration + other.duration)/2,
        (this->effectsIntensity + other.effectsIntensity)/2,
        max(this->usesLeft,other.usesLeft)
    );
}

float Potion::calculateEffectiveness() {
    return effectsIntensity*(duration/10)*(effectsList.size()/2);
}