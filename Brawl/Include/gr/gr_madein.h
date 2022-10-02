#pragma once

#include <so/so_damage.h>
#include <so/so_damage_attacker_info.h>
#include <so/so_collision_log.h>
#include <gr/gr_seq_yakumono.h>


class grOverwriteAttackData {
    char _spacer[0x40];
};

class grMadein : public grSeqYakumono {
protected:
    char _spacer[8];
    grOverwriteAttackData* overwriteAttackData;
    char _spacer2[60];
public:

    void createAttackPoint();
    void createAttackPointNormal(grOverwriteAttackData* attackData);
    void deleteAttackPoint();
    void deleteHitPoint();
    void endEntity();
    float getEntityFrame();
    grOverwriteAttackData* getOverwriteAttackData();
    void initializeEntity();
    bool isEndEntity();
    bool isFrameEndOffset(float unk);
    bool isFrameOffset(float unk);
    void pauseEntity(bool isPause);
    void setAttack(float unk1, void* unk2);
    void setHitPoint(float unk1, void* unk2, void* unk3, int unk4, int unk5);
    void setMatrix(Matrix matrix, void* unk1);
    void setMotion(int unk1);
    void setMotionDetails(int unk1, int unk2, int unk3, int unk4, int unk5);
    void setupYakumonoClass();
    void startEntity();
    void startEntityAutoLoop(int unk1);
    void startEntityLoop();
    void switchToMatrix();

    grMadein(char* taskName);
    virtual void onDamage(int index, soDamage* damage, soDamageAttackerInfo* attackerInfo);
    virtual void onInflictEach(soCollisionLog* collisionLog, float power);
    virtual void receiveCollMsg_Landing(grCollStatus* collStatus, grCollisionJoint* collisionJoint, bool unk3);
    virtual void startup(gfArchive* data, u32 unk1, u32 unk2);
    virtual void update(float frameDiff);
    virtual ~grMadein();
};