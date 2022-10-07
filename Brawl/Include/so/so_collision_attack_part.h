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

struct soCollisionAttackData {
    int power;
    Vec3f offsetPos;
    float size;
    int vector;
    int reactionEffect;
    int reactionFix;
    int reactionAdd;
    float field_0x24;
    float field_0x28;
    float field_0x2c;
    unsigned int field_0x30_0 : 9; // up to 0x1ff
    unsigned int field_0x30_1 : 10; // up to 0x3ff
    unsigned int field_0x30_2 : 3; // up to 0x7
    bool field_0x30_3 : 1; // up to 0x1
    unsigned int field_0x30_4 : 4; // up to 0xf
    CollisionAttackElementType elementType : 5; // up to 0x1f
    unsigned int field_0x34_0 : 2; // up to 0x3
    unsigned int field_0x34_1 : 5; // up to 0x1f
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
//    int field_0x30;
//    int field_0x34;
//    int field_0x38;
//    int field_0x3c;
};
