#pragma once

#include <StaticAssert.h>
#include <ft/fighter.h>
#include <so/article/so_article.h>
#include <so/stageobject.h>
#include <types.h>
#include <ut/ut_uncopyable.h>
#include <it/it_value_accesser.h>
#include <it/it_create.h>

class itCustomizerInterface;

class BaseItem : public StageObject, public soStatusEventObserver, public soSituationEventObserver, public soCollisionAttackEventObserver, public soCollisionShieldEventObserver, public soCollisionReflectorEventObserver, public soCollisionSearchEventObserver, public soGimmickEventObserver, public soArticle {
protected:
    soModuleAccesser moduleAccesser;
    char _428[1808];

public:
    enum StatusKind {
        Status_Standby = 0x0,
        Status_Initialize = 0x1,
        Status_Have = 0x2,
        Status_Fall = 0x3,
        Status_Landing = 0x4,
        Status_Throw = 0x5,
        Status_Lost = 0x6,
        Status_Born = 0x7,
    };

    enum WorkId {

        Instance_Work_Int_Have_Node_Index = 0x10000007,
        Instance_Work_Int_Life_Time = 0x10000009,
        Instance_Work_Int_Target_Task_Id = 0x10000013,
        Instance_Work_Int_Hit_Kind = 0x10000016,

        Instance_Work_Float_Hp = 0x11000006,
        Instance_Work_Float_Target_Pos_X = 0x11000007,
        Instance_Work_Float_Target_Pos_Y = 0x11000008,
        Instance_Work_Float_Base_Scale = 0x1100000c,

        Instance_Work_Flag_Target_Found = 0x12000007,
    };

    int m_instanceId;
    union {
        struct {
            ItemKind m_itemKind;
        };
        struct {
            itKind m_kind;
            u32 m_variation;
        };
    };
    int m_creatorTaskId;
    itKind m_lotCreateKind;
    itCustomizerInterface* m_customizer;
    u8 m_2260;
    char _2261[7];
    itArchive* m_itArchive;
    float m_strongestAttackPower;
    int m_hitStopFrames;
    char _2280[13368];
    int m_articleId;
    char _15652[4];
    int m_genParamId;
    char _15660[4];
    int m_attackHitTaskId;
    int m_searchHitTaskId;
    int m_15672;
    int m_15676;
    u8 searchHitCollisionIndex;
    u8 m_15681;
    char _15682[2];
    Vec3f m_searchHitPos;
    Vec3f m_startInhaledPos;
    char _15708[4];

    BaseItem(itCreate* create);
    virtual void processUpdate();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processHit();
    virtual void processFixCamera();
    virtual void processGameProc();
    virtual void renderPre();
    virtual void renderDebug();
    virtual ~BaseItem();

    // TODO: Verify parameters
    virtual void reset(Vec3f* pos, float lr, float);
    virtual void remove();
    virtual int getArticleId();
    virtual int getArticleEventManageId();
    virtual int getTaskId();
    virtual void linkOwner(int, int);
    virtual void unlinkOwner(int);
    virtual bool isActiveArticle();
    virtual void deactivateArticle();
    virtual void changeMotion(int, int);
    virtual void changeStatus(int actionID);
    virtual void setVisibilityWhole(u8);
    virtual void setVisibilityWholeForce(u8);
    virtual u8 getVisibilityWhole();
    virtual void setSituationKind(int);
    virtual bool isConstraint();
    virtual void setConstraintTargetNode(int);
    virtual bool isSyncOwnerStatus();
    virtual void setSyncOwnerStatus(int);
    virtual void setAttackPowerMulPattern(float);
    virtual void setArticleId(int articleId);
    virtual void setLogAttackInfo(soLogAttackInfo* logAttackInfo);
    virtual soLogAttackInfo getLogAttackInfo();
    virtual void updateLogAttackInfo();
    virtual void deactivate();
    virtual void have(int taskId, int, int);
    virtual void action(int);
    virtual void setGlowAttack(int glowAttack);
    virtual int getGlowAttack();
    virtual void notifyEventChangeStatus(int statusKind, int prevStatusKind, soStatusData* statusData, soModuleAccesser* moduleAccesser);
    virtual void notifyEventChangeSituation(SituationKind kind, SituationKind prevKind, soModuleAccesser* moduleAccesser);
    virtual void notifyEventCollisionAttack(float power, soCollisionLog* collisionLog, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionAttackCheck(u32 flags);
    virtual void notifyEventCollisionShield(soCollisionAttackModule* attackModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser, float power, float posX, float);
    virtual void notifyEventCollisionShieldSearch(soCollisionSearchModule* searchModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionShieldCheck();
    virtual void notifyEventCollisionReflector(soCollisionAttackModule* attackModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser, float power, float posX, float);
    virtual void notifyEventCollisionReflectorSearch(soCollisionSearchModule* searchModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionReflectorCheck();
    virtual void notifyEventCollisionSearch(soCollisionLog* collisionLog, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionSearchCheck();
    virtual void notifyEventInfoWindow(int);
    virtual void notifyEventGimmick(soGimmickEventInfo* eventInfo, int* taskId);
    virtual void presentEventGimmick(soGimmickEventInfo* eventInfo, int sendID);
    virtual void onDamage(int, void*);
    virtual bool isUseTurnDamage();
    virtual bool isUseSpeedDamage();
    virtual bool isUseShake();

    float getParam(itValueAccesser::ParamFloat param);
    int getParam(itValueAccesser::ParamInt param);
    float getParamFloat(u32 param);
    bool isHaved();
    int getTeamOwnerTaskId();

    void setSafePos(Vec2f* pos);
    void warp(Vec3f* pos);
    void setVanishMode(bool);
};
static_assert(sizeof(BaseItem) == 0x3d60, "Class is wrong size!");

class itCustomizerInterface : public utUnCopyable {
public:
    virtual ~itCustomizerInterface();
    virtual void onConstruct(BaseItem* item);
    virtual void onDestruct(BaseItem* item);
    virtual void onReset(BaseItem* item);
    virtual void onProcessUpdate(BaseItem* item);
    virtual void onProcessFixPosition(BaseItem* item);
    virtual void onProcessHit(BaseItem* item);
    virtual void onProcessFixCamera(BaseItem* item);
    virtual void onProcessGameProc(BaseItem* item);
    virtual void onRenderPre(BaseItem* item);
    virtual void onRenderDebug(BaseItem* item);
    virtual void onNotifyEventChangeStatus(BaseItem* item, int statusKind, int prevStatusKind, soStatusData* statusData, soModuleAccesser* moduleAccesser);
    virtual void onNotifyEventAnimCmd(BaseItem* item, acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    virtual void onNotifyEventCollisionAttackCheck(BaseItem* item, int hitTaskId);
    virtual bool onNotifyEventCollisionSearch(BaseItem* item, soCollisionLog* collisionLog);
    virtual bool onNotifyEventCollisionSearchCheck(BaseItem* item, int searchHitTaskId, u8 searchHitCollisionIndex, Vec3f* searchHitPos);
    virtual void onNotifyEventLink(BaseItem* item, void* unk1, soModuleAccesser* moduleAccesser, StageObject*, int unk4);
    virtual bool onNotifyEventCaptureStatus(BaseItem* item); // TODO
    virtual void onNotifyEventGimmick(BaseItem* item, soGimmickEventInfo* eventInfo, int* taskId);
    virtual void onUpdateKinetic(BaseItem* item);
    virtual void onUpdateAiDir(BaseItem* item, Vec2f*, Vec2f*, Vec2f*, Vec2f*);
    virtual void onUpdateAiMove(BaseItem* item, Vec2f*, Vec2f*, Vec2f*);
    virtual bool onSearchTarget(BaseItem* item, int* taskId, Vec3f pos, int);
    virtual int onShoot(BaseItem* item, float lr, float, int);
    virtual int onShootBlanks(BaseItem* item, int);
    virtual int onGetBullet(BaseItem* item);
    virtual void onThrowAttack(BaseItem* item, float, float* lr, Vec3f*, Vec3f*, float* powerMulStatus, bool*);
    virtual void onAction(BaseItem* item, int, float rate);
    virtual int onResult(BaseItem* item);
    virtual bool onHave(BaseItem* item, int);
    virtual bool onPreDamageCheck(BaseItem* item, int, void*);
    virtual bool onDamage(BaseItem* item, int, void*);
    virtual bool onReflect(BaseItem* item);
    virtual void onPreBound(BaseItem* item, float*, u32);
    virtual bool onRemoveModelConstraint(BaseItem* item, int);
    virtual bool onEnumFighter(BaseItem* item, Fighter* fighter);
    virtual int onGetLayerType(BaseItem* item);
    virtual bool isTreadPassive(BaseItem* item);
    virtual bool isUseTurnDamage(BaseItem* item);
    virtual bool isUseSpeedDamage(BaseItem* item);
    virtual bool isUseShake(BaseItem* item);
    virtual bool isUseScaleZ(BaseItem* item);
    virtual bool isUseThrowRotParam(BaseItem* item);
    virtual bool isSafe(BaseItem* item);
    virtual bool isConstraintHave(BaseItem* item);
    virtual bool isReferenceControlerHave(BaseItem* item);
    virtual u32 getKineticFlags(BaseItem* item);
    virtual bool isUsePhysics(BaseItem* item);
};
static_assert(sizeof(itCustomizerInterface) == 12, "Class is wrong size!");

template <class T>
class itCustomizer : public itCustomizerInterface {
    virtual ~itCustomizer();
};

class itNullCustomizer : public itCustomizer<itNullCustomizer> {
    virtual ~itNullCustomizer();

    static itNullCustomizer* getInstance();
};
static_assert(sizeof(itNullCustomizer) == 12, "Class is wrong size!");