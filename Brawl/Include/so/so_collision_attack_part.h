#pragma once

#include <mt/mt_vector.h>

enum CollisionAttackElementType {
    Element_Type_Normal	    = 0x0,
    Element_Type_None	    = 0x1,
    Element_Type_Slash      = 0x2,
    Element_Type_Electric   = 0x3,
    Element_Type_Freezing   = 0x4,
    Element_Type_Flame	    = 0x5,
    Element_Type_Coin   	= 0x6,
    Element_Type_Reverse    = 0x7,
    Element_Type_Trip       = 0x8,
    Element_Type_Sleep      = 0x9,
    Element_Type_None2      = 0xA,
    Element_Type_Bury       = 0xB,
    Element_Type_Stun       = 0xC,
    Element_Type_Sparkle    = 0xD,
    Element_Type_Flower     = 0xE,
    Element_Type_YellowSteam = 0xF,
    Element_Type_None3      = 0x10,
    Element_Type_Grass      = 0x11,
    Element_Type_Water      = 0x12,
    Element_Type_Darkness   = 0x13,
    Element_Type_Paraylyze  = 0x14,
    Element_Type_Aura       = 0x15,
    Element_Type_Plunge     = 0x16,
    Element_Type_Down       = 0x17,
    Element_Type_Flinchless = 0x18,
    Element_Type_None5      = 0x19,
    Element_Type_None6      = 0x1A,
    Element_Type_None7      = 0x1B,
    Element_Type_None8      = 0x1C,
    Element_Type_None9      = 0x1D,
    Element_Type_None10     = 0x1E,
    Element_Type_None11     = 0x1F,
};

enum CollisionAttackHitSoundLevel {
    Hit_Sound_Level_Small = 0x0,
    Hit_Sound_Level_Medium = 0x1,
    Hit_Sound_Level_Large = 0x2,
    Hit_Sound_Level_Huge = 0x3,
};

enum CollisionAttackHitSoundType {
    Hit_Sound_Type_NoneUnique = 0x0,
    Hit_Sound_Type_Punch = 0x1,
    Hit_Sound_Type_Kick = 0x2,
    Hit_Sound_Type_Slash = 0x3,
    Hit_Sound_Type_Coin = 0x4,
    Hit_Sound_Type_Bat = 0x5,
    Hit_Sound_Type_Paper = 0x6, // (Harisen)
    Hit_Sound_Type_Electric = 0x7,
    Hit_Sound_Type_Fire = 0x8,
    Hit_Sound_Type_Water = 0x9,
    Hit_Sound_Type_Blank = 0xA,
    Hit_Sound_Type_Explosion = 0xB,
    Hit_Sound_Type_Blank2 = 0xC,
    Hit_Sound_Type_SnakeThud = 0xD, // Exclusive to Snake
    Hit_Sound_Type_IkeSlam = 0xE, // Exclusive to Ike
    Hit_Sound_Type_DededeThwomp = 0xF, // Exclusive to Dedede
    Hit_Sound_Type_Magic = 0x10,
    Hit_Sound_Type_Shell = 0x11,
    Hit_Sound_Type_PeachSlap = 0x12, // Exclusive to Peach
    Hit_Sound_Type_PeachPan = 0x13, // Exclusive to Peach
    Hit_Sound_Type_PeachClub = 0x14, // Exclusive to Peach
    Hit_Sound_Type_PeachRacket = 0x15, // Exclusive to Peach
    Hit_Sound_Type_LucarioAura = 0x16, // Exclusive to Lucario
    Hit_Sound_Type_MarthTreble = 0x17, // Exclusive to Marth
    Hit_Sound_Type_MarioCoin = 0x18, // Exclusive to Mario
    Hit_Sound_Type_MarioStatic = 0x19, // Exclusive to Mario
    Hit_Sound_Type_LuigiCoin = 0x1A, // Exclusive to Luigi
    Hit_Sound_Type_NessBat = 0x1B, // Exclusive to Ness
    Hit_Sound_Type_Frost = 0x1C,
};

union soCollisionAttackData {
    struct {
        int power;
        Vec3f offsetPos;
        float size;
        int vector;
        int reactionEffect;
        int reactionFix;
        int reactionAdd;
        float tripRate;
        float hitstopMultiplier;
        float sdiMultiplier;
        unsigned int field_0x30_0 : 9; // up to 0x1ff
        bool isCollisionCategoryUnk1 : 1;
        bool isCollisionCategoryItems1 : 1; // Soccer Ball, Blast Box etc.
        bool isCollisionCategoryUnk2 : 1;
        bool isCollisionCategoryUnk3 : 1;
        bool isCollisionCategoryUnk4 : 1;
        bool isCollisionCategoryUnk5 : 1;
        bool isCollisionCategoryItems2 : 1; // Barrel, Crate etc.
        bool isCollisionCategoryUnk6 : 1;
        bool isCollisionCategoryUnk7 : 1;
        bool isCollisionCategoryFighter : 1;
        unsigned int field_0x30_2 : 3; // up to 0x7
        bool field_0x30_3 : 1; // up to 0x1
        unsigned int field_0x30_4 : 4; // up to 0xf
        CollisionAttackElementType elementType : 5; // up to 0x1f
        CollisionAttackHitSoundLevel hitSoundLevel : 2; // up to 0x3
        CollisionAttackHitSoundType hitSoundType : 5; // up to 0x1f
        bool field_0x34_2 : 1;
        bool field_0x34_3 : 1;
        bool field_0x34_4 : 1;
        bool field_0x34_5 : 1;
        bool field_0x34_6 : 1;
        bool field_0x34_7 : 1;
        unsigned int field_0x34_8 : 9; // up to 0x1ff
        unsigned int field_0x34_9 : 10; // ~up to 0x3ff
        unsigned int field_0x38_0 : 16; // up to 0xffff
        bool field_0x38_1 : 1;
        bool field_0x38_2 : 1;
        bool field_0x38_3 : 1;
        unsigned int field_0x38_4 : 3; // up to 0x7
        bool field_0x38_5 : 1;
        bool field_0x38_6 : 1;
        bool field_0x38_7 : 1;
        bool field_0x38_8 : 1;
        bool field_0x38_9 : 1;
        unsigned int field_0x38_10 : 5; // up to 0x1f;
        bool field_0x3c_0 : 1;
        unsigned int field_0x3c_1 : 31; // ~up to 0x7fffffff
    }bits;

    struct {
        int power;
        Vec3f offsetPos;
        float size;
        int vector;
        int reactionEffect;
        int reactionFix;
        int reactionAdd;
        float tripRate;
        float hitstopMultiplier;
        float sdiMultiplier;
        unsigned int field_0x30_0 : 9; // up to 0x1ff
        unsigned int collisionCategory : 10; // up to 0x3ff;
        unsigned int field_0x30_2 : 3; // up to 0x7
        bool field_0x30_3 : 1; // up to 0x1
        unsigned int field_0x30_4 : 4; // up to 0xf
        CollisionAttackElementType elementType : 5; // up to 0x1f
        CollisionAttackHitSoundLevel hitSoundLevel : 2; // up to 0x3
        CollisionAttackHitSoundType hitSoundType : 5; // up to 0x1f
        bool field_0x34_2 : 1;
        bool field_0x34_3 : 1;
        bool field_0x34_4 : 1;
        bool field_0x34_5 : 1;
        bool field_0x34_6 : 1;
        bool field_0x34_7 : 1;
        unsigned int field_0x34_8 : 9; // up to 0x1ff
        unsigned int field_0x34_9 : 10; // ~up to 0x3ff
        unsigned int field_0x38_0 : 16; // up to 0xffff
        bool field_0x38_1 : 1;
        bool field_0x38_2 : 1;
        bool field_0x38_3 : 1;
        unsigned int field_0x38_4 : 3; // up to 0x7
        bool field_0x38_5 : 1;
        bool field_0x38_6 : 1;
        bool field_0x38_7 : 1;
        bool field_0x38_8 : 1;
        bool field_0x38_9 : 1;
        unsigned int field_0x38_10 : 5; // up to 0x1f;
        bool field_0x3c_0 : 1;
        unsigned int field_0x3c_1 : 31; // ~up to 0x7fffffff
    }masks;
};
