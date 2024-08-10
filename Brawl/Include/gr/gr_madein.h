#pragma once

#include <gr/gr_seq_yakumono.h>
#include <mt/mt_vector.h>
#include <so/collision/so_collision_log.h>
#include <so/damage/so_damage.h>
#include <so/damage/so_damage_attacker_info.h>

class grMadein : public grSeqYakumono {
public:
    class AttackInfo {
    public:
        float m_size;
        Vec3f m_offsetPos;
        char _spacer[0x18];
        int m_preset;
    };

    class HitPointInfo {
        Vec3f m_startOffsetPos;
        Vec3f m_endOffsetPos;
        char _spacer[12];
        float m_size;
        float m_lastDamageTaken;
        float m_lastSide;
        char _spacer2[8];
        int m_lastPlayerHit;
        int m_nodeIndex;
    };

    class StageHitData {
        Vec3f m_startOffsetPos;
        Vec3f m_endOffsetPos;
        float m_size;
        char _spacer[8];
        int m_nodeIndex;
        char _spacer2[20];
    };

    enum Category {
        Category_Gimmick = 0x0,
        Category_Wall = 0x1,
        Category_Enemy = 0x2
    };

protected:
    AttackInfo* m_attackInfo;
    HitPointInfo* m_hitPointInfo;
    soCollisionAttackData* m_overwriteAttackData;
    StageHitData* m_stageHitData;
    bool m_300_7 : 1;                 // | 0x80
    bool m_hasAttack : 1;             // | 0x40
    bool m_hasHitPoint : 1;           // | 0x20
    bool m_isHit : 1;                 // | 0x10
    Category m_category : 2; // | 0x4, 0x8
    bool m_isLandedOn : 1;            // | 0x2
    bool m_useLandCheck : 1;          // | 0x1
    char _301[11];
    int m_landerTaskId;
    char _316[50];

public:
    void createAttackPoint();
    void createAttackPointNormal(soCollisionAttackData* attackData);
    void deleteAttackPoint();
    void deleteHitPoint();
    void endEntity();
    float getEntityFrame();
    soCollisionAttackData* getOverwriteAttackData();
    void initializeEntity();
    bool isEndEntity();
    bool isFrameEndOffset(float unk);
    bool isFrameOffset(float unk);
    void pauseEntity(bool isPause);
    void setAttack(float size, Vec3f* offsetPos);
    void setHitPoint(float size, Vec3f* startOffsetPos, Vec3f* endOffsetPos, bool, int nodeIndex);
    void setMatrix(Matrix matrix, void* unk1);
    void setMotion(u32 anmIndex);
    void setMotionDetails(u32 anmChrIndex, u32 anmVisIndex, u32 anmTexPatIndex, u32 anmTexSrtIndex, u32 anmClrIndex);
    void setupYakumonoClass();
    void startEntity();
    void startEntityAutoLoop();
    void startEntityLoop(int unk1);
    void switchToMatrix();

    grMadein(const char* taskName);
    virtual void setTgtNode(const char* unk1);
    virtual u32 getTgtNode();
    virtual void onDamage(int index, soDamage* damage, soDamageAttackerInfo* attackerInfo);
    virtual void onInflictEach(soCollisionLog* collisionLog, float power);
    virtual void receiveCollMsg_Landing(grCollStatus* collStatus, grCollisionJoint* collisionJoint, bool isFirstContact);
    virtual void startup(gfArchive* data, u32 unk1, u32 unk2);
    virtual void update(float deltaFrame);
    virtual ~grMadein();

    static grMadein* create(int mdlIndex, const char* tgtNodeName, const char* taskName, HeapType heapType);
};