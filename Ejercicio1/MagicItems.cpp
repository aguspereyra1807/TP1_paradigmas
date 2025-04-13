#include "MagicItems.h"

// Potion

Potion::Potion(double power, int level, set<string> effects, int duration, float intensity, int uses)
    : MagicItem(power, level, "Potion"), duration(duration), effectsIntensity(intensity) {
        effectsList = effects; 
        usesLeft = uses;
        effectiveness = calculateEffectiveness();
}

double Potion::getDamage(float enemyResistance) {
    if (usesLeft > 0) {
        usesLeft--;
        return magicPower*(1-enemyResistance)*effectiveness;
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
    return effectsIntensity*(static_cast<float>(duration)/10)*(static_cast<float>(effectsList.size())/2);
}

// SpellsBook

SpellsBook::SpellsBook(double power, int level, MAGIC_T type, int pages, string language)
    :   MagicItem(power, level, "Spells Book"),
        pagesAmount(pages),
        spellsType(type),
        language(language) {
}
    
    
    double SpellsBook::getDamage(float enemyResistance) {
        float intensity;
        switch (spellsType) {
            case MAGIC_T::Light:
                intensity = 1.0;
                break;
            case MAGIC_T::Anti:
                intensity = 1.25;
                break;
            case MAGIC_T::Dark:
                intensity = 1.5;
                break;
            default:
                intensity = 0.9;
                break;
        }
        return magicPower*intensity*(pagesAmount/100)*(1-enemyResistance);
    }
    
MAGIC_T SpellsBook::getSpellsType() const {
    return spellsType;
}

string SpellsBook::getLanguage() const {
    return language;
}

// Amulet

Amulet::Amulet(double power, int level, MATERIAL_T material, MAGIC_T magicType, int rarity, EFFECT_T effect)
    :   MagicItem(power, level, "Amulet"),
        material(material),
        magicType(magicType),
        rarity(rarity),
        characterEffect(effect) {
            intensity = calculateIntensity();
}

double Amulet::getDamage(float enemyResistance) {
    return magicPower*intensity*(1-enemyResistance);
}

MATERIAL_T Amulet::getMaterial() const {
    return material;
}

MAGIC_T Amulet::getMagicType() const {
    return magicType;
}

int Amulet::getRarity() const {
    return rarity;
}

EFFECT_T Amulet::getCharacterEffect() const {
    return characterEffect;
}

float Amulet::calculateIntensity() {
    float x, y;
    switch (magicType)
    {
    case MAGIC_T::Light:
        x = 1.0;
        break;
    case MAGIC_T::Anti:
        x = 1.25;
        break;
    case MAGIC_T::Dark:
        x = 1.5;
        break;
    default:
        x = 0.9;
        break;
    }
    switch (material)
    {
    case MATERIAL_T::Wood:
        y = 0.5;
        break;
    case MATERIAL_T::Steel:
        y = 1.0;
        break;
    case MATERIAL_T::Diamond:
        y = 1.5;
        break;
    default:
        y = 0.9;
        break;
    }
    return x*y;
}

// Cane

Cane::Cane(double power, int level, MATERIAL_T material, EFFECT_T effect, int length, float hardness)
    :   MagicItem(power, level, "Cane"),
        material(material),
        hitEffect(effect),
        length(length),
        hardness(hardness) {
            strength = calculateStrength();
}

double Cane::getDamage(float enemyResistance) {
    float x, y;
    switch (hitEffect)
    {
    case EFFECT_T::Thorns:
        x = 1.0;
        break;
    case EFFECT_T::Burn:
        x = 1.25;
        break;
    case EFFECT_T::Electrify:
        x = 1.5;
        break;
    default:
        x = 0.9;
        break;
    }
    switch (material)
    {
    case MATERIAL_T::Wood:
        y = 0.5;
        break;
    case MATERIAL_T::Steel:
        y = 1.0;
        break;
    case MATERIAL_T::Diamond:
        y = 1.5;
        break;
    default:
        y = 0.9;
        break;
    }
    return x*y*strength*(1-enemyResistance);
}

MATERIAL_T Cane::getMaterial() const {
    return material;
}

EFFECT_T Cane::getHitEffect() const {
    return hitEffect;
}

int Cane::getLength() const {
    return length;
}

float Cane::getHardness() const {
    return hardness;
}

float Cane::calculateStrength() {
    return (length/2)*hardness;
}