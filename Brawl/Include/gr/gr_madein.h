#pragma once

#include <so/so_damage.h>
#include <so/so_damage_attacker_info.h>
#include <so/so_collision_log.h>


class grOverwriteAttackData {
    char _spacer[0x40];
};

class grMadein : public grSeqYakumono {
protected:
    char _spacer[8]
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

    virtual void onDamage(int index, soDamage* damage, soDamageAttackerInfo* attackerInfo);
    virtual void onInflictEach(soCollisionLog* collisionLog, float power);








};