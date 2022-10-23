#pragma once

#include <mt/mt_vector.h>
#include <so/so_damage.h>
#include <so/so_damage_attacker_info.h>
#include <so/so_collision_log.h>
#include <gr/gr_seq_yakumono.h>

class grMadeinAttackInfo {
    public:
        float size;
        Vec3f offsetPos;
        char _spacer[0x18];
        int preset;
};

class grMadeinHitPointInfo {
    Vec3f startOffsetPos;
    Vec3f endOffsetPos;
    char _spacer[12];
    float size;
    float lastDamageTaken;
    float lastSide;
    char _spacer2[8];
    int lastPlayerHit;
    int nodeIndex;
};

class StageHitData {
    Vec3f startOffsetPos;
    Vec3f endOffsetPos;
    float size;
    char _spacer[8];
    int nodeIndex;
    char _spacer2[20];
};


class grMadein : public grSeqYakumono {
protected:
    grMadeinAttackInfo* attackInfo;
    grMadeinHitPointInfo* hitPointInfo;
    soCollisionAttackData* overwriteAttackData;
    StageHitData* stageHitData;
    char _spacer2[56];
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
    void setHitPoint(float size, Vec3f* startOffsetPos, Vec3f* endOffsetPos, int unk4, int nodeIndex);
    void setMatrix(Matrix matrix, void* unk1);
    void setMotion(u32 anmIndex);
    void setMotionDetails(u32 anmChrIndex, u32 anmVisIndex, u32 anmTexPatIndex, u32 anmTexSrtIndex, u32 anmClrIndex);
    void setupYakumonoClass();
    void startEntity();
    void startEntityAutoLoop();
    void startEntityLoop(int unk1);
    void switchToMatrix();

    grMadein(char* taskName);
    virtual void setTgtNode(char* unk1);
    virtual u32 getTgtNode();
    virtual void onDamage(int index, soDamage* damage, soDamageAttackerInfo* attackerInfo);
    virtual void onInflictEach(soCollisionLog* collisionLog, float power);
    virtual void receiveCollMsg_Landing(grCollStatus* collStatus, grCollisionJoint* collisionJoint, bool unk3);
    virtual void startup(gfArchive* data, u32 unk1, u32 unk2);
    virtual void update(float frameDiff);
    virtual ~grMadein();

    static grMadein* create(int mdlIndex, char* tgtNodeName, char* taskName, HeapType heapType);
};