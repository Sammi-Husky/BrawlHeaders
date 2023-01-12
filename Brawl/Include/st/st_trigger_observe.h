#pragma once

#include <types.h>
#include <mt/mt_vector.h>
#include <gf/gf_area.h>
#include <gf/gf_callback.h>
#include <StaticAssert.h>

struct GimmickAreaData {
    char _0[16];
    short m_16;
    short m_18;
    char _20[4];
    Vec2f m_pos;
    Vec2f m_range;
};

struct SquareBeltConveyorGimmickAreaData : GimmickAreaData {
    Vec3f m_conveyorPos;
    float m_speed;
    bool m_isRightDirection;
    char _spacer[7];

    STATIC_CHECK(sizeof(SquareBeltConveyorGimmickAreaData) == 64)
};

struct SquareWaterGimmickAreaData : GimmickAreaData {
    float m_swimHeight;
    bool m_canDrown;
    char _45[3];
    float m_currentSpeed;
    char m_52[4];

    STATIC_CHECK(sizeof(SquareWaterGimmickAreaData) == 56)
};

class stObsTriggerCB : public gfCallback {

    char _spacer[8];

    virtual ~stObsTriggerCB();
    virtual gfArea* getAreaPointer();
    virtual bool getAreaID(int* areaID);
    virtual void setAreaSleep(bool isSleep);
};

class stObsTriggerArea : public stObsTriggerCB {

    gfArea* m_area;
    GimmickAreaData m_gimmickAreaData;

    virtual void userProc();
    virtual ~stObsTriggerArea();
    virtual gfArea* getAreaPointer();
    virtual bool getAreaID(int* areaID);
    virtual void setAreaSleep(bool isSleep);
    virtual GimmickAreaData* getAreaDataPointer();
    virtual void setArea(gfArea* area);
};

class stObsTriggerSquareBeltConveyorCB : public stObsTriggerArea {
    char _spacer[4];

    virtual void userProc();
    virtual ~stObsTriggerSquareBeltConveyorCB();

    STATIC_CHECK(sizeof(stObsTriggerSquareBeltConveyorCB) == 0x40)
};