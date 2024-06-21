#pragma once

#include <StaticAssert.h>
#include <so/area/so_area_module_impl.h>
#include <so/collision/so_collision_hit_part.h>
#include <so/collision/so_collision_log.h>
#include <so/stageobject.h>
#include <types.h>

class grYakumono;

struct ykHitGroupInfo {
    char _0[8];
    soCollisionHitPartsInfo* m_hitPartsInfo;
};

struct ykData {
    int m_numHitGroups;
    ykHitGroupInfo* m_hitGroupsInfo;
};

struct ykAreaData : ykData {
    soAreaInit* m_areaInit;
};

class Yakumono : public StageObject, public soCollisionAttackEventObserver {
public:
    void setSituationKind(int situationKind);
    void setCollisionHitOpponentCategory(int unk1, bool unk2);
    void setCollisionHitSelfCatagory(int category);
    void setReactionFrame(int reactionFrame);
    void setTeamOwnerId(int teamOwnerId);
    void setTeam(int teamId);
    int getTeam();

    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void renderDebug();
    virtual ~Yakumono();
    virtual void updatePosture(bool);
    virtual soKind soGetKind();
    virtual int soGetSubKind();
    virtual void updateNodeSRT();

    virtual float getAttackPosX(int index);
    virtual float getHitPosX(int index);
    virtual void initAttackPosXWork(int unk1, int unk2);
    virtual void initHitPosXWork(int unk1, int unk2);
    virtual void presentEventGimmick(soGimmickEventInfo* eventInfo, int sendID);

    virtual void notifyEventCollisionAttack(float power, soCollisionLog* collisionLog, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionAttackCheck(u32 flags);

    grYakumono* m_ground;
    char _104[4];
    soCollisionLog m_collisionLog;
    char _116[4];
    soModuleAccesser moduleAccesser;
    ykData* m_data;
    char _spacer[457];
    char _pad[3];
};
static_assert(sizeof(Yakumono) == 856, "Class is wrong size!");
