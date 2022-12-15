#pragma once
#include <StaticAssert.h>
#include <gr/gr_gimmick.h>
#include <so/collision/so_collision_attack_part.h>
#include <so/collision/so_collision_log.h>
#include <so/damage/so_damage.h>
#include <so/damage/so_damage_attacker_info.h>
#include <yk/yakumono.h>

class grYakumono : public grGimmick {
public:
    struct AttackData {
        float m_unk1;
        Vec3f m_offsetPos;
        float m_size;
        int m_vector;
        int m_reactionEffect;
        int m_reactionFix;
        int m_reactionAdd;
        char _spacer[4];
        CollisionAttackElementType m_elementType;
        bool m_isClankable;
        bool m_unk2;
        bool m_unk3;
        bool m_unk4;
        char _spacer2[0xC];
        unsigned int m_detectionRate;
        CollisionAttackHitSoundLevel m_hitSoundLevel;
        CollisionAttackHitSoundType m_hitSoundType;
        bool m_unk5;
        bool m_isShapeCapsule;
        char _spacer3[6];
        unsigned int m_nodeIndex;
        int m_power;

        STATIC_CHECK(sizeof(AttackData) == 88)
    };

    struct AttackDetails {
        union {
            unsigned int m_collisionCategoryMask;
            struct {
                unsigned int _pad : 22;
                bool m_isCollisionCategoryUnk1 : 1;
                bool m_isCollisionCategoryItems1 : 1; // Soccer Ball, Blast Box etc.
                bool m_isCollisionCategoryUnk2 : 1;
                bool m_isCollisionCategoryUnk3 : 1;
                bool m_isCollisionCategoryUnk4 : 1;
                bool m_isCollisionCategoryUnk5 : 1;
                bool m_isCollisionCategoryItems2 : 1; // Barrel, Crate etc.
                bool m_isCollisionCategoryUnk6 : 1;
                bool m_isCollisionCategoryUnk7 : 1;
                bool m_isCollisionCategoryFighter : 1;
            };
        };
        char m_unk1;
        bool m_unk2;
        char _spacer[2];
        CollisionAttackFacingRestriction m_facingRestriction;
        float m_hitstopMultiplier;

        STATIC_CHECK(sizeof(AttackDetails) == 16)
    };

protected:
    Yakumono* m_yakumono;

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
    virtual void setAreaGimmick(soAreaData* areaData, soAreaInit* areaInit, ykAreaData* data, bool unk4);
    virtual void setAttackGimmick(int index, int groupIndex, u32 nodeIndex, AttackData* grAttackData,
                                  AttackDetails* grAttackDetails);
    virtual void setSoCollisionAttackData(soCollisionAttackData* attackData, AttackData* grAttackData,
                                          AttackDetails* grAttackDetails);
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