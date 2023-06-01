#pragma once

#include <mt/mt_vector.h>
#include <types.h>

enum CollisionAttackElementType {
    Element_Type_Normal = 0x0,
    Element_Type_None = 0x1,
    Element_Type_Slash = 0x2,
    Element_Type_Electric = 0x3,
    Element_Type_Freezing = 0x4,
    Element_Type_Flame = 0x5,
    Element_Type_Coin = 0x6,
    Element_Type_Reverse = 0x7,
    Element_Type_Trip = 0x8,
    Element_Type_Sleep = 0x9,
    Element_Type_None2 = 0xA,
    Element_Type_Bury = 0xB,
    Element_Type_Stun = 0xC,
    Element_Type_Sparkle = 0xD,
    Element_Type_Flower = 0xE,
    Element_Type_YellowSteam = 0xF,
    Element_Type_None3 = 0x10,
    Element_Type_Grass = 0x11,
    Element_Type_Water = 0x12,
    Element_Type_Darkness = 0x13,
    Element_Type_Paralyze = 0x14,
    Element_Type_Aura = 0x15,
    Element_Type_Plunge = 0x16,
    Element_Type_Down = 0x17,
    Element_Type_Flinchless = 0x18,
    Element_Type_None5 = 0x19,
    Element_Type_None6 = 0x1A,
    Element_Type_None7 = 0x1B,
    Element_Type_None8 = 0x1C,
    Element_Type_None9 = 0x1D,
    Element_Type_None10 = 0x1E,
    Element_Type_None11 = 0x1F,
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
    Hit_Sound_Type_SnakeThud = 0xD,    // Exclusive to Snake
    Hit_Sound_Type_IkeSlam = 0xE,      // Exclusive to Ike
    Hit_Sound_Type_DededeThwomp = 0xF, // Exclusive to Dedede
    Hit_Sound_Type_Magic = 0x10,
    Hit_Sound_Type_Shell = 0x11,
    Hit_Sound_Type_PeachSlap = 0x12,   // Exclusive to Peach
    Hit_Sound_Type_PeachPan = 0x13,    // Exclusive to Peach
    Hit_Sound_Type_PeachClub = 0x14,   // Exclusive to Peach
    Hit_Sound_Type_PeachRacket = 0x15, // Exclusive to Peach
    Hit_Sound_Type_LucarioAura = 0x16, // Exclusive to Lucario
    Hit_Sound_Type_MarthTreble = 0x17, // Exclusive to Marth
    Hit_Sound_Type_MarioCoin = 0x18,   // Exclusive to Mario
    Hit_Sound_Type_MarioStatic = 0x19, // Exclusive to Mario
    Hit_Sound_Type_LuigiCoin = 0x1A,   // Exclusive to Luigi
    Hit_Sound_Type_NessBat = 0x1B,     // Exclusive to Ness
    Hit_Sound_Type_Frost = 0x1C,
};

enum CollisionAttackFacingRestriction {
    Facing_Restriction_Normal = 0x0,
    Facing_Restriction_TowardsUserDirectionOfHorizontalMomentum = 0x1,
    Facing_Restriction_AwayFromWhereTargetIsFacing = 0x2,
    Facing_Restriction_ForwardFromDirectionOfUser = 0x3,
    Facing_Restriction_BackwardsFromDirectionOfUser = 0x4,
    Facing_Restriction_AwayFromCenterOfCollision = 0x5,
};

struct soCollisionAttackAbsoluteData {
    int m_power;
    int m_vector;
    int m_reactionEffect;
    int m_reactionFix;
    int m_reactionAdd;
    float m_tripRate;
    float m_hitstopMultiplier;
    float m_sdiMultiplier;
    u32 _32;
};

struct soCollisionAttackData {
    int m_power;
    Vec3f m_offsetPos;
    float m_size;
    int m_vector;
    int m_reactionEffect;
    int m_reactionFix;
    int m_reactionAdd;
    float m_tripRate;
    float m_hitstopMultiplier;
    float m_sdiMultiplier;
    union {
        struct {
            unsigned int nodeIndex : 9;    // up to 0x1ff
            bool isCollisionCategory9 : 1; // Skyword platforms, Hanenbow platforms, stage blocks
            bool isCollisionCategory8 : 1; // Soccer Ball, Blast Box etc.
            bool isCollisionCategory7 : 1;
            bool isCollisionCategory6 : 1; // Ground
            bool isCollisionCategory5 : 1;
            bool isCollisionCategory4 : 1;
            bool isCollisionCategory3 : 1; // Barrel, Crate etc.
            bool isCollisionCategory2 : 1;
            bool isCollisionCategory1 : 1; // SSE enemies
            bool isCollisionCategory0 : 1; // Fighter
            bool isCollisionSituationODD : 1;
            bool isCollisionSituationAir : 1;
            bool isCollisionSituationGround : 1;
            bool field_0x30_3 : 1;                          // up to 0x1
            bool isCollisionPartRegion3 : 1;                // Usually body, legs
            bool isCollisionPartRegion2 : 1;                // Usually Shin
            bool isCollisionPartRegion1 : 1;                // Usually forearm
            bool isCollisionPartRegion0 : 1;                // Usually head, pelvis, arm, tail, wing, item
            CollisionAttackElementType elementType : 5;     // up to 0x1f
            CollisionAttackHitSoundLevel hitSoundLevel : 2; // up to 0x3
            CollisionAttackHitSoundType hitSoundType : 5;   // up to 0x1f
            bool isClankable : 1;
            bool field_0x34_3 : 1;
            bool field_0x34_4 : 1;
            bool isBlockable : 1;
            bool isReflectable : 1;
            bool isAbsorbable : 1;
            unsigned int addedShieldDamage : 9; // up to 0x1ff
            unsigned int field_0x34_9 : 10;     // ~up to 0x3ff
            unsigned int detectionRate : 16;    // up to 0xffff
            bool field_0x38_1 : 1;
            bool ignoreInvincibility : 1;
            bool ignoreIntangibility : 1;
            CollisionAttackFacingRestriction facingRestriction : 3; // up to 0x7
            bool field_0x38_5 : 1;
            bool enableFriendlyFire : 1;
            bool disableHitstop : 1;
            bool disableHitGfx : 1;
            bool disableFlinch : 1;
            unsigned int field_0x38_10 : 5; // up to 0x1f;
            bool isShapeCapsule : 1;
            unsigned int field_0x3c_1 : 31; // ~up to 0x7fffffff
        } m_bits;

        struct {
            unsigned int nodeIndex : 9;                     // up to 0x1ff
            unsigned int collisionCategory : 10;            // up to 0x3ff;
            unsigned int collisionSituation : 3;            // up to 0x7
            bool field_0x30_3 : 1;                          // up to 0x1
            unsigned int collisionPart : 4;                 // up to 0xf
            CollisionAttackElementType elementType : 5;     // up to 0x1f
            CollisionAttackHitSoundLevel hitSoundLevel : 2; // up to 0x3
            CollisionAttackHitSoundType hitSoundType : 5;   // up to 0x1f
            bool isClankable : 1;
            bool field_0x34_3 : 1;
            bool field_0x34_4 : 1;
            bool isBlockable : 1;
            bool isReflectable : 1;
            bool isAbsorbable : 1;
            unsigned int addedShieldDamage : 9; // up to 0x1ff
            unsigned int field_0x34_9 : 10;     // ~up to 0x3ff
            unsigned int detectionRate : 16;    // up to 0xffff
            bool field_0x38_1 : 1;
            bool ignoreInvincibility : 1;
            bool ignoreIntangibility : 1;
            CollisionAttackFacingRestriction facingRestriction : 3; // up to 0x7
            bool field_0x38_5 : 1;                                  // break throws?
            bool enableFriendlyFire : 1;
            bool disableHitstop : 1;
            bool disableHitGfx : 1;
            bool disableFlinch : 1;
            unsigned int field_0x38_10 : 5; // up to 0x1f;
            bool isShapeCapsule : 1;
            unsigned int field_0x3c_1 : 31; // ~up to 0x7fffffff
        } m_masks;
    };
};
static_assert(sizeof(soCollisionAttackData) == 64, "Class is wrong size!");
