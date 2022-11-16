#pragma once
#include <StaticAssert.h>
#include <gr/gr_gimmick.h>
#include <so/so_collision_attack_part.h>
#include <so/so_collision_log.h>
#include <so/so_damage.h>
#include <so/so_damage_attacker_info.h>
#include <yk/yakumono.h>

struct grYakumonoAttackData {
    float unk1;
    Vec3f offsetPos;
    float size;
    int vector;
    int reactionEffect;
    int reactionFix;
    int reactionAdd;
    char _spacer[4];
    CollisionAttackElementType elementType;
    bool isClankable;
    bool unk2;
    bool unk3;
    bool unk4;
    char _spacer2[0xC];
    unsigned int detectionRate;
    CollisionAttackHitSoundLevel hitSoundLevel;
    CollisionAttackHitSoundType hitSoundType;
    bool unk5;
    bool isShapeCapsule;
    char _spacer3[6];
    unsigned int nodeIndex;
    int power;
};

struct grYakumonoAttackDetails {
    union {
        unsigned int collisionCategoryMask;
        struct {
            unsigned int _pad : 22;
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
        };
    };
    char unk1;
    bool unk2;
    char _spacer[2];
    CollisionAttackFacingRestriction facingRestriction;
    float hitstopMultiplier;
};

class grYakumono : public grGimmick {
protected:
    Yakumono* yakumono;

public:
    grYakumono(char* taskName);
    virtual void processUpdate();
    virtual void startup(gfArchive* data, u32 unk1, u32 unk2);
    virtual void setValid(u32 unk1);
    virtual void setValidAttachedEffect(u32 unk1);
    virtual void preExit();
    virtual void setTransparency(u32 unk1, u32 unk2);
    virtual ~grYakumono();

    virtual void onDamage(int index, soDamage* damage, soDamageAttackerInfo* attackerInfo);
    virtual void onInflict(int* unk1, u32 unk2); // TODO
    virtual void onInflictEach(soCollisionLog* collisionLog, float power);
    virtual void onGimmickEvent(soGimmickEventInfo* eventInfo, int* taskId);
    virtual bool enableYakumono(u32 unk1);
    virtual bool disableYakumono(u32 unk1, u32 unk2);
    virtual bool enableHit(u32 unk1, u32 unk2);
    virtual bool disableHit(u32 unk1, u32 unk2);
    virtual bool disableAttack(u32 unk1);
    virtual bool enableArea();
    virtual bool disableArea();
    virtual bool setSleepArea(bool unk1);
    virtual bool setTeamYakumonoOwnerId(u32 teamOwnerId);
    virtual bool setTeamYakumono(u32 teamId, u32 teamOwnerId);
    virtual bool getTeamYakumono(u32 unk1);
    virtual bool setOffsetAttack(Vec3f* offsetPos, int index);
    virtual void setAreaGimmick(soAreaData* areaData, soAreaInit* areaInit, ykData* data, bool unk4);
    virtual void setAttackGimmick(int index, int groupIndex, u32 nodeIndex, grYakumonoAttackData* grAttackData,
                                  grYakumonoAttackDetails* grAttackDetails);
    virtual void setSoCollisionAttackData(soCollisionAttackData* attackData, grYakumonoAttackData* grAttackData,
                                          grYakumonoAttackDetails* grAttackDetails);
    virtual void setAttackGimmickDetails(soCollisionAttackData* attackData, float size, float tripRate,
                                         float hitstopMultiplier, float sdiMultiplier, int power, Vec3f* offsetPos,
                                         int vector, int reactionEffect, int reactionFix, int reactionAdd,
                                         u32 nodeIndex, u32 collisionCategoryMask, u32 collisionSituationMask,
                                         bool unk1, u32 collisionPartMask, CollisionAttackElementType elementType,
                                         CollisionAttackHitSoundLevel hitSoundLevel, CollisionAttackHitSoundType hitSoundType,
                                         bool isClankable, bool unk2, bool unk3, bool isBlockable, bool isReflectable,
                                         bool isAbsorbable, u32 unk4, u32 detectionRate, bool unk5, bool ignoreInvincibility,
                                         bool ignoreIntangibility, CollisionAttackFacingRestriction facingRestriction,
                                         bool unk6, bool unk7, bool disableHitstop, bool disableHitGfx,
                                         bool disableFlinch, u32 addedShieldDamage, bool isShapeCapsule);
    virtual bool isEnableAttackPersonAttacked(u32 unk1, u32 unk2, u32 unk3);
    virtual bool isEnableAttackAttribute(u32 unk1, u32 unk2);

    void clearAttackerInfo();
    int getPlayerNumber(int* unk1);
    int getPlayerNumber(grCollStatus* collStatus);
    bool isSubFighter(int* unk1);
    void setAreaShape(int unk1, float* unk2, float* unk3);
    void setAttackSize(int index, int unk2, float size);
    void setAttackTargetCategory(int index, u32 categoryMask);
    void setSleepAttack(bool isSleep);
    void setSleepHit(bool isSleep);
    void setSituationODD();

    STATIC_CHECK(sizeof(grYakumono) == 0x150)
};