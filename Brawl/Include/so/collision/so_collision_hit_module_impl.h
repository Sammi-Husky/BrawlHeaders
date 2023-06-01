#pragma once

#include <StaticAssert.h>
#include <so/collision/so_collision.h>
#include <so/collision/so_collision_hit_group.h>
#include <so/so_array.h>
#include <so/event/so_event_observer.h>
#include <so/event/so_event_presenter.h>
#include <so/so_null.h>
#include <types.h>

class soModuleAccesser;

class soCollisionHitModule : public soNullable {
public:
    virtual ~soCollisionHitModule();
    virtual void activate(float, float, float, u32 collisionIndex, u32 collisionHitGroupIndex);
    virtual void activate(float, float, float, void*, u32 collisionIndex);
    virtual void reset(float, float, float, u32 collisionIndex, u32 collisionHitGroupIndex);
    virtual void deactivate();
    virtual void begin();
    virtual void clean();
    virtual void sleep(bool);
    virtual void add(void*, u32 collisionHitGroupIndex);
    virtual void add(int*, u32 collisionHitGroupIndex);
    virtual void resetStatusAll(u32 collisionHitGroupIndex);
    virtual void set(u32 collisionHitPartIndex, soCollisionHitData* hitData, u32 collisionHitGroupIndex);
    virtual void set(void*, u32 collisionHitGroupIndex);
    virtual void set(int*, u32 collisionHitGroupIndex);
    virtual void setStatus(u32 collisionHitPartIndex, int status, u32 collisionHitGroupIndex);
    virtual void setStatusNode(int, int status, u32 collisionHitGroupIndex);
    virtual void setStatusNodeDefault(int, int status, u32 collisionHitGroupIndex);
    virtual void setStatusAll(int status, u32 collisionHitGroupIndex);
    virtual void setWhole(int, u32 collisionHitGroupIndex);
    virtual int getWhole(u32 collisionHitGroupIndex);
    virtual void setCheckCatch(bool, u32 collisionHitGroupIndex);
    virtual void update(float, float, float, int, u32 collisionHitGroupIndex);
    virtual void update(float, float, float, int);
    virtual void resetStatusGlobal(u32 collisionHitGroupIndex);
    virtual void setXluGlobal(u32 collisionHitGroupIndex);
    virtual void cancelXluGlobal(u32 collisionHitGroupIndex);
    virtual void setXluFrameGlobal(int xluFrameGlobal, u32 collisionHitGroupIndex);
    virtual void setInvincibleGlobal(u32 collisionHitGroupIndex);
    virtual void cancelInvincibleGlobal(u32 collisionHitGroupIndex);
    virtual void setInvincibleFrameGlobal(int invincibleFrameGlobal, bool override, u32 collisionHitGroupIndex);
    virtual int getInvincibleFrameGlobal(u32 collisionHitGroupIndex);
    virtual int getGlobal(u32 collisionHitGroupIndex);
    virtual int getStatus(u32 collisionHitPartIndex, u32 collisionHitGroupIndex);
    virtual int getTotalStatus(u32 collisionHitGroupIndex);
    virtual float getDurabilityMulFromAttackData();
    virtual int getPartSize(u32 collisionHitGroupIndex);
    virtual u32 getPartHeight(u32 collisionHitPartIndex, u32 collisionHitGroupIndex);
    virtual void setNoTeam(bool);
    virtual void setGlobalOffset(u8, u32 collisionHitGroupIndex);
    virtual void setMultiSituation(u32 situationIndex, u32 collisionHitGroupIndex);
    virtual void initMultiSituation(u32 collisionHitGroupIndex);
    virtual void setOpponentCategory(u32 category, bool, u32 collisionHitGroupIndex);
    virtual void setSelfCategory(u32 category, u32 collisionHitGroupIndex);
    virtual void checkLog();
    virtual u32 getGroupNum();
    virtual bool isReactionFrame();
    virtual short getReactionFrame();
    virtual void setReactionFrame(short reactionFrame);
    virtual void setPosX(float posX, u32 collisionGroupIndex);
    virtual float getPosX(u32 collisionGroupIndex);
    virtual Vec3f getCenterPos(u16 index, u32 collisionHitGroupIndex);
    virtual void renderDebug();
};
static_assert(sizeof(soCollisionHitModule) == 8, "Class is wrong size!");

class soCollisionHitModuleImpl : public soCollisionHitModule, public soStatusEventObserver, public soAnimCmdEventObserver, public soEventPresenter<soCollisionHitEventObserver> {

public:
    soModuleAccesser* m_moduleAccesser;
    char _48[8];
    soCollision m_collision;
    char _80[8];
    soArray<soCollisionHitGroup>* m_collisionHitGroupArray;
    char _92[8];
    short m_reactionFrame;
    char _102[2];

    virtual ~soCollisionHitModuleImpl();
    virtual void activate(float, float, float, u32 collisionIndex, u32 collisionHitGroupIndex);
    virtual void activate(float, float, float, void*, u32 collisionIndex);
    virtual void reset(float, float, float, u32 collisionIndex, u32 collisionHitGroupIndex);
    virtual void deactivate();
    virtual void begin();
    virtual void clean();
    virtual void sleep(bool);
    virtual void add(void*, u32 collisionHitGroupIndex);
    virtual void add(int*, u32 collisionHitGroupIndex);
    virtual void resetStatusAll(u32 collisionHitGroupIndex);
    virtual void set(u32 collisionHitPartIndex, soCollisionHitData* hitData, u32 collisionHitGroupIndex);
    virtual void set(void*, u32 collisionHitGroupIndex);
    virtual void set(int*, u32 collisionHitGroupIndex);
    virtual void setStatus(u32 collisionHitPartIndex, int status, u32 collisionHitGroupIndex);
    virtual void setStatusNode(int, int status, u32 collisionHitGroupIndex);
    virtual void setStatusNodeDefault(int, int status, u32 collisionHitGroupIndex);
    virtual void setStatusAll(int status, u32 collisionHitGroupIndex);
    virtual void setWhole(int, u32 collisionHitGroupIndex);
    virtual int getWhole(u32 collisionHitGroupIndex);
    virtual void setCheckCatch(bool, u32 collisionHitGroupIndex);
    virtual void update(float, float, float, int, u32 collisionHitGroupIndex);
    virtual void update(float, float, float, int);
    virtual void resetStatusGlobal(u32 collisionHitGroupIndex);
    virtual void setXluGlobal(u32 collisionHitGroupIndex);
    virtual void cancelXluGlobal(u32 collisionHitGroupIndex);
    virtual void setXluFrameGlobal(int xluFrameGlobal, u32 collisionHitGroupIndex);
    virtual void setInvincibleGlobal(u32 collisionHitGroupIndex);
    virtual void cancelInvincibleGlobal(u32 collisionHitGroupIndex);
    virtual void setInvincibleFrameGlobal(int invincibleFrameGlobal, bool override, u32 collisionHitGroupIndex);
    virtual int getInvincibleFrameGlobal(u32 collisionHitGroupIndex);
    virtual int getGlobal(u32 collisionHitGroupIndex);
    virtual int getStatus(u32 collisionHitPartIndex, u32 collisionHitGroupIndex);
    virtual int getTotalStatus(u32 collisionHitGroupIndex);
    virtual float getDurabilityMulFromAttackData();
    virtual int getPartSize(u32 collisionHitGroupIndex);
    virtual u32 getPartHeight(u32 collisionHitPartIndex, u32 collisionHitGroupIndex);
    virtual void setNoTeam(bool);
    virtual void setGlobalOffset(u8, u32 collisionHitGroupIndex);
    virtual void setMultiSituation(u32 situationIndex, u32 collisionHitGroupIndex);
    virtual void initMultiSituation(u32 collisionHitGroupIndex);
    virtual void setOpponentCategory(u32 category, bool, u32 collisionHitGroupIndex);
    virtual void setSelfCategory(u32 category, u32 collisionHitGroupIndex);
    virtual void checkLog();
    virtual u32 getGroupNum();
    virtual bool isReactionFrame();
    virtual short getReactionFrame();
    virtual void setReactionFrame(short reactionFrame);
    virtual void setPosX(float posX, u32 collisionGroupIndex);
    virtual float getPosX(u32 collisionGroupIndex);
    virtual Vec3f getCenterPos(u16 index, u32 collisionHitGroupIndex);
    virtual void renderDebug();

    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    virtual void notifyEventChangeStatus(int statusKind, int prevStatusKind, soStatusData* statusData, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soCollisionHitModuleImpl) == 104, "Class is wrong size!");