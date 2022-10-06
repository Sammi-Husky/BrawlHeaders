#pragma once

#include <so/so_damage.h>
#include <so/so_damage_attacker_info.h>
#include <so/so_collision_log.h>
#include <gr/gr_seq_yakumono.h>

class grMadeinAttackInfo {
    public:
        float radius;
        float height;
        float pitch;
        float yaw;
        char _spacer[0x18];
        int preset;
};

class grMadein : public grSeqYakumono {
protected:
    grMadeinAttackInfo* attackInfo;
    char _spacer[4];
    soCollisionAttackData* overwriteAttackData;
    char _spacer2[60];
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
    void setAttack(float unk1, float* unk2);
    void setHitPoint(float unk1, void* unk2, void* unk3, int unk4, int unk5);
    void setMatrix(Matrix matrix, void* unk1);
    void setMotion(int unk1);
    void setMotionDetails(int unk1, int unk2, int unk3, int unk4, int unk5);
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