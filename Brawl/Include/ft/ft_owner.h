#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <ft/fighter.h>

class ftOwner {
    void* m_data;
    void* m_input;
    short _8;
    u8 _10;
    u8 _11;

public:
    virtual ~ftOwner();
    virtual bool isSubOwner();
    virtual void setDamage(float damage, bool);
    virtual float getDamage();
    virtual void setStartDamage(float startDamage);
    virtual float getStartDamage();
    virtual float getHitPoint();
    virtual void setBeatCount(int playerIndex, int beatCount);
    virtual u32 getCheerDefeatFrame();
    virtual void setSuicideCount(short suicideCount);
    virtual void setLogFloat(float, u32 index1, u32 index2);
    virtual void addLogFloat(float, u32 index1, u32 index2);
    virtual void setLogInt(int, u32 index1, u32 index2);
    virtual void addLogInt(int, u32 index1, u32 index2);
    virtual void setLogFlag(bool, u32 index1, u32 index2);
    virtual void onLogFlag(u32 index1, u32 index2);
    virtual void offLogFlag(u32 index1, u32 index2);
    virtual void setLogActionInfo(void*);
    virtual void addAttackInfo(void*);
    virtual void addAttackPattern(void*);

    int getStockCount();
    void setMetal(bool);
    void setFinal(bool, bool);
    void setRabbitCap(bool);
    void setReflector(bool);
    void setFlower(bool);
    void setCurry(bool);
    void setInfiniteScaling(Fighter::ScalingKind, Fighter::ScalingType);
    void setHitPointMax(float);
    void setSlipMul(float);
    void setSlipInterval(bool);
};
static_assert(sizeof(ftOwner) == 16, "Class is wrong size!");