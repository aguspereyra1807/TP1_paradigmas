#pragma once

#include "WeaponTypes.h"

enum class MAGIC_T {Dark, Light, Anti};
enum class EFFECT_T {Thorns, Burn, Electrify};

class Potion: public MagicItem {
    public:
        Potion(double power, int level, set<string> effects, int duration, float intensity, int uses);

        double getDamage(float enemyResistance) override;

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
        SpellsBook(double power, int level, MAGIC_T type, int pages, string language);
        
        double getDamage(float enemyResistance) override;
        
        MAGIC_T getSpellsType() const;
        string getLanguage() const;
        
    private:
        const int pagesAmount;
        const MAGIC_T spellsType;
        const string language;
};

class Amulet: public MagicItem {
    public:
        Amulet(double power, int level, MATERIAL_T material, MAGIC_T magicType, int rarity, EFFECT_T effect);

        double getDamage(float enemyResistance) override;
        
        MATERIAL_T getMaterial() const;
        MAGIC_T getMagicType() const;
        int getRarity() const;
        EFFECT_T getCharacterEffect() const;

    private:
        const MATERIAL_T material;
        const MAGIC_T magicType;
        float intensity;
        const int rarity; // 1-5
        const EFFECT_T characterEffect;

        float calculateIntensity();
};

class Cane: public MagicItem {
    public:
        Cane(double power, int level, MATERIAL_T material, EFFECT_T effect, int length, float hardness);

        double getDamage(float enemyResistance) override;

        MATERIAL_T getMaterial() const;
        EFFECT_T getHitEffect() const;
        int getLength() const;
        float getHardness() const;

    private:
        const MATERIAL_T material;
        const EFFECT_T hitEffect;
        const int length;
        const float hardness;
        float strength;


        float calculateStrength();

};