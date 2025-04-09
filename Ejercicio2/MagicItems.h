#pragma once

#include <set>
#include "WeaponTypes.h"

enum class MAGIC_TYPE {Dark, Light, Anti};

class Potion: public MagicItem {
    public:
        Potion(double power, int level, set<string> effects, int duration, float intensity, int uses);

        double getDamage(float enemyPhysicalResistance, float enemyMagicResistance) override;

        void showEffects() const;
        void addEffect(string effect);
        int getDuration() const;
        float getIntensity() const;
        int getUsesLeft() const;
        
        unique_ptr<Potion> operator+(Potion& other) const;
        
        private:
        set<string> effectsList;
        const int duration;
        const float effectsIntensity; // intensity >= 1
        int usesLeft;
        float effectiveness;
        
        float calculateEffectiveness();
};

class SpellsBook: public MagicItem {
    public:
        SpellsBook(MAGIC_TYPE type, int pages, string language, string category, string author);
        MAGIC_TYPE getSpellsType();

        double getDamage(float enemyPhysicalResistance, float enemyMagicResistance) override;
        
    private:
        int pagesAmount;
        MAGIC_TYPE spellsType;
        string language;
        string category;
        string author;

};