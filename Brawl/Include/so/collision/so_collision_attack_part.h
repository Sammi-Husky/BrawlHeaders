#pragma once

#include <mt/mt_vector.h>
#include <types.h>
#include <so/collision/so_collision.h>
#include <so/so_array.h>

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
    enum ElementType {
        Element_Normal = 0x0,
        Element_None = 0x1,
        Element_Slash = 0x2,
        Element_Electric = 0x3,
        Element_Freezing = 0x4,
        Element_Flame = 0x5,
        Element_Coin = 0x6,
        Element_Reverse = 0x7,
        Element_Trip = 0x8,
        Element_Sleep = 0x9,
        Element_None2 = 0xA,
        Element_Bury = 0xB,
        Element_Stun = 0xC,
        Element_Sparkle = 0xD,
        Element_Flower = 0xE,
        Element_YellowSteam = 0xF,
        Element_None3 = 0x10,
        Element_Grass = 0x11,
        Element_Water = 0x12,
        Element_Darkness = 0x13,
        Element_Paralyze = 0x14,
        Element_Aura = 0x15,
        Element_Plunge = 0x16,
        Element_Down = 0x17,
        Element_Flinchless = 0x18,
        Element_None5 = 0x19,
        Element_None6 = 0x1A,
        Element_None7 = 0x1B,
        Element_None8 = 0x1C,
        Element_None9 = 0x1D,
        Element_None10 = 0x1E,
        Element_None11 = 0x1F,
    };

    enum HitSoundLevel {
        Hit_Sound_Small = 0x0,
        Hit_Sound_Medium = 0x1,
        Hit_Sound_Large = 0x2,
        Hit_Sound_Huge = 0x3,
    };

    enum HitSoundType {
        Hit_Sound_NoneUnique = 0x0,
        Hit_Sound_Punch = 0x1,
        Hit_Sound_Kick = 0x2,
        Hit_Sound_Slash = 0x3,
        Hit_Sound_Coin = 0x4,
        Hit_Sound_Bat = 0x5,
        Hit_Sound_Paper = 0x6, // (Harisen)
        Hit_Sound_Electric = 0x7,
        Hit_Sound_Fire = 0x8,
        Hit_Sound_Water = 0x9,
        Hit_Sound_Blank = 0xA,
        Hit_Sound_Explosion = 0xB,
        Hit_Sound_Blank2 = 0xC,
        Hit_Sound_SnakeThud = 0xD,    // Exclusive to Snake
        Hit_Sound_IkeSlam = 0xE,      // Exclusive to Ike
        Hit_Sound_DededeThwomp = 0xF, // Exclusive to Dedede
        Hit_Sound_Magic = 0x10,
        Hit_Sound_Shell = 0x11,
        Hit_Sound_PeachSlap = 0x12,   // Exclusive to Peach
        Hit_Sound_PeachPan = 0x13,    // Exclusive to Peach
        Hit_Sound_PeachClub = 0x14,   // Exclusive to Peach
        Hit_Sound_PeachRacket = 0x15, // Exclusive to Peach
        Hit_Sound_LucarioAura = 0x16, // Exclusive to Lucario
        Hit_Sound_MarthTreble = 0x17, // Exclusive to Marth
        Hit_Sound_MarioCoin = 0x18,   // Exclusive to Mario
        Hit_Sound_MarioStatic = 0x19, // Exclusive to Mario
        Hit_Sound_LuigiCoin = 0x1A,   // Exclusive to Luigi
        Hit_Sound_NessBat = 0x1B,     // Exclusive to Ness
        Hit_Sound_Frost = 0x1C,
    };

    enum FacingRestriction {
        Facing_Restriction_Normal = 0x0,
        Facing_Restriction_TowardsUserDirectionOfHorizontalMomentum = 0x1,
        Facing_Restriction_AwayFromWhereTargetIsFacing = 0x2,
        Facing_Restriction_ForwardFromDirectionOfUser = 0x3,
        Facing_Restriction_BackwardsFromDirectionOfUser = 0x4,
        Facing_Restriction_AwayFromCenterOfCollision = 0x5,
    };


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
            ElementType elementType : 5;     // up to 0x1f
            HitSoundLevel hitSoundLevel : 2; // up to 0x3
            HitSoundType hitSoundType : 5;   // up to 0x1f
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
            FacingRestriction facingRestriction : 3; // up to 0x7
            bool field_0x38_5 : 1;
            bool enableFriendlyFire : 1;
            bool disableHitstop : 1;
            bool disableHitGfx : 1;
            bool disableFlinch : 1;
            unsigned int field_0x38_10 : 5; // up to 0x1f;
            bool isShapeCapsule : 1;
            bool isDangerZone : 1; // custom
            unsigned int field_0x3c_2 : 30; // ~up to 0x3fffffff
        } m_bits;

        struct {
            unsigned int nodeIndex : 9;                     // up to 0x1ff
            unsigned int collisionCategory : 10;            // up to 0x3ff;
            unsigned int collisionSituation : 3;            // up to 0x7
            bool field_0x30_3 : 1;                          // up to 0x1
            unsigned int collisionPart : 4;                 // up to 0xf
            ElementType elementType : 5;     // up to 0x1f
            HitSoundLevel hitSoundLevel : 2; // up to 0x3
            HitSoundType hitSoundType : 5;   // up to 0x1f
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
            FacingRestriction facingRestriction : 3; // up to 0x7
            bool field_0x38_5 : 1;                                  // break throws?
            bool enableFriendlyFire : 1;
            bool disableHitstop : 1;
            bool disableHitGfx : 1;
            bool disableFlinch : 1;
            unsigned int field_0x38_10 : 5; // up to 0x1f;
            bool isShapeCapsule : 1;
            bool isDangerZone : 1; // custom
            unsigned int field_0x3c_2 : 30; // ~up to 0x3fffffff
        } m_masks;
    };

    inline soCollisionAttackData() {
        m_tripRate = 1.0;
        m_hitstopMultiplier = 1.0;
        m_sdiMultiplier = 1.0;
        m_masks.field_0x38_10 = 0;
    }
};
static_assert(sizeof(soCollisionAttackData) == 64, "Class is wrong size!");

struct soCollisionAttackAbsolute {
    soCollisionAttackData m_attackData;
    char _0x40[4];
    Vec3f m_nodeGlobalPos;
    char _0x50[15];
    u8 m_index;
    int m_groupIndex;
    bool m_isAttack;
    char _0x65[3];

    soCollisionAttackAbsolute();
    ~soCollisionAttackAbsolute();
};

class soCollisionAttackPart {
    int m_0x0;
    soCollisionAttackData m_attackData;
    soArrayVector<clTarget, 7> m_clTargetArrayVector;
    int m_groupIndex;
    char _0x8c[4];

public:
    soCollisionAttackPart();
    soCollisionAttackPart(u8, bool);
    ~soCollisionAttackPart();
};
static_assert(sizeof(soCollisionAttackPart) == 0x90, "Class is wrong size!");
