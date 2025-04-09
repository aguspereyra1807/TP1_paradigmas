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
        SpellsBook(double power, int level, MAGIC_TYPE type, int pages, string language, string category, string author);
        
        double getDamage(float enemyPhysicalResistance, float enemyMagicResistance) override;
        
        MAGIC_TYPE getSpellsType() const;
        string getLanguage() const;
        string getCategory() const;
        string getAuthor() const;
        
    private:
        const int pagesAmount;
        const MAGIC_TYPE spellsType;
        const string language;
        const string category;
        const string author;

};