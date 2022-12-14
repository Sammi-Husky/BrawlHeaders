#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <so/so_null.h>
#include <mt/mt_vector.h>
#include <so/so_event_observer.h>

class soModuleAccesser;

class soEffectModule : public soNullable {
public:
    virtual ~soEffectModule();
    virtual void activate();
    virtual void deactivate();
    virtual void begin();
    virtual void update(bool);
    virtual bool req(float scale, u32 effectID, Vec3f* pos, Vec3f* rot, u32, int);
    virtual bool req2D(float scale, u32 effectID, Vec3f* pos, Vec3f* rot, u32);
    virtual bool req(float scale, u32 effectID, int, Vec3f* pos, Vec3f* rot, Vec3f* posRange, Vec3f* rotRange, bool, u32);
    virtual bool req(float scale, u32 effectID, int, int*, Vec3f* pos, Vec3f* rot, Vec3f* posRange, Vec3f* rotRange, bool, u32);
    virtual bool reqAttachGround(float scale, u32 effectID, int*, Vec3f* pos, Vec3f* rot, Vec3f* rotRange, u32);
    virtual bool reqFollow(float scale, u32 effectID, int, Vec3f*, Vec3f*, bool, u32, u32 effectIDAdd, int);
    virtual bool reqContinual(float, u32 effectID, int, bool, u32 index);
    virtual void removeContinual(u32 index);
    virtual void removeAllContinual();
    virtual void reqTime(float scale, u32 effectID, int, Vec3f* pos, Vec3f* rot, u32);
    virtual void reqTimeFollow(float scale, u32 effectID, int, int, Vec3f*, Vec3f*, u32);
    virtual void removeTime(int);
    virtual void removeAllTime();
    virtual void reqEmit(u32 effectID, u32);
    virtual void remove(int);
    virtual void removeAll(u32);
    virtual void kill(int, bool, bool);
    virtual void killKind(bool, bool, int);
    virtual void killAll(u32, bool, bool);
    virtual bool reqAfterImage(float scale, float, int nodeID1, int nodeID2, int, short, Vec3f*, Vec3f*, u32, u32 effectId, int, Vec3f* pos, Vec3f*, u8, u8);
    virtual bool removeAfterImage(int, int);
    virtual void removeAllAfterImage(u32, int);
    virtual void setPos(int, Vec3f* pos);
    virtual void setRot(int, Vec3f* rot);
    virtual void setScale(int, Vec3f* scale);
    virtual bool isExistEffect(int);
    virtual void setVisible(int, bool);
    virtual void setWhole(bool);
    virtual void reqPause(bool);
    virtual void fillScreen(int index, u32, int, int);
    virtual void clearScreen(int index, u32);
    virtual float getDeadEffectRotZ(Vec3f*, bool* out);
    virtual void reqCommon(float, int index);
    virtual void removeCommon(int);
    virtual void resetCommon();
    virtual bool isEndCommon();
    virtual bool isExistCommon(int);
    virtual void reqScreen(int index);
    virtual void removeScreen(int index);
    virtual void setSyncVisibility(bool);
    virtual bool isSyncVisibility();
    virtual void setSyncScale(bool);
    virtual bool isSyncScale();
    virtual void setShieldEffect(int);
    virtual void ignoreScaleZ(bool);

    STATIC_CHECK(sizeof(soEffectModule) == 8)
};

class soEffectModuleImpl : public soEffectModule, public soAnimCmdEventObserver, public soStatusEventObserver, public soModelEventObserver,
        public soCollisionAttackEventObserver, public soCollisionShieldEventObserver {
    soModuleAccesser* m_moduleAccesser;
    char _72[240];
public:
    virtual ~soEffectModuleImpl();
    virtual void activate();
    virtual void deactivate();
    virtual void begin();
    virtual void update(bool);
    virtual bool req(float scale, u32 effectID, Vec3f* pos, Vec3f* rot, u32, int);
    virtual bool req2D(float scale, u32 effectID, Vec3f* pos, Vec3f* rot, u32);
    virtual bool req(float scale, u32 effectID, int, Vec3f* pos, Vec3f* rot, Vec3f* posRange, Vec3f* rotRange, bool, u32);
    virtual bool req(float scale, u32 effectID, int, int*, Vec3f* pos, Vec3f* rot, Vec3f* posRange, Vec3f* rotRange, bool, u32);
    virtual bool reqAttachGround(float scale, u32 effectID, int*, Vec3f* pos, Vec3f* rot, Vec3f* rotRange, u32);
    virtual bool reqFollow(float scale, u32 effectID, int, Vec3f*, Vec3f*, bool, u32, u32 effectIDAdd, int);
    virtual bool reqContinual(float, u32 effectID, int, bool, u32 index);
    virtual void removeContinual(u32 index);
    virtual void removeAllContinual();
    virtual void reqTime(float scale, u32 effectID, int, Vec3f* pos, Vec3f* rot, u32);
    virtual void reqTimeFollow(float scale, u32 effectID, int, int, Vec3f*, Vec3f*, u32);
    virtual void removeTime(int);
    virtual void removeAllTime();
    virtual void reqEmit(u32 effectID, u32);
    virtual void remove(int);
    virtual void removeAll(u32);
    virtual void kill(int, bool, bool);
    virtual void killKind(bool, bool, int);
    virtual void killAll(u32, bool, bool);
    virtual bool reqAfterImage(float scale, float, int nodeID1, int nodeID2, int, short, Vec3f*, Vec3f*, u32, u32 effectId, int, Vec3f* pos, Vec3f*, u8, u8);
    virtual bool removeAfterImage(int, int);
    virtual void removeAllAfterImage(u32, int);
    virtual void setPos(int, Vec3f* pos);
    virtual void setRot(int, Vec3f* rot);
    virtual void setScale(int, Vec3f* scale);
    virtual bool isExistEffect(int);
    virtual void setVisible(int, bool);
    virtual void setWhole(bool);
    virtual void reqPause(bool);
    virtual void fillScreen(int index, u32, int, int);
    virtual void clearScreen(int index, u32);
    virtual float getDeadEffectRotZ(Vec3f*, bool* out);
    virtual void reqCommon(float, int index);
    virtual void removeCommon(int);
    virtual void resetCommon();
    virtual bool isEndCommon();
    virtual bool isExistCommon(int);
    virtual void reqScreen(int index);
    virtual void removeScreen(int index);
    virtual void setSyncVisibility(bool);
    virtual bool isSyncVisibility();
    virtual void setSyncScale(bool);
    virtual bool isSyncScale();
    virtual void setShieldEffect(int);
    virtual void ignoreScaleZ(bool);

    virtual bool notifyEventCollisionShieldCheck();
    virtual void notifyEventDestructInstance(soModuleAccesser* moduleAccesser);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    virtual void notifyEventChangeStatus(int unk1, int unk2, void* unk3, soModuleAccesser* moduleAccesser);
    virtual void notifyEventCollisionAttack(void* unk1, void* unk2, soModuleAccesser* moduleAccesser);
    virtual void notifyEventCollisionShield(float, float, float, void*, void*, int, soModuleAccesser* moduleAccesser);
    virtual void notifyEventCollisionShieldSearch(void*, void*);
    virtual u32 isObserv(char unk1);

    STATIC_CHECK(sizeof(soEffectModuleImpl) == 312)
};

