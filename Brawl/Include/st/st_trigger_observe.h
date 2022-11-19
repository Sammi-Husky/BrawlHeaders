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

struct BeltConveyorGimmickAreaData : GimmickAreaData {
    Vec3f m_conveyorPos;
    float m_speed;
    bool m_isRightDirection;
    char _spacer[7];

    STATIC_CHECK(sizeof(BeltConveyorGimmickAreaData) == 64)
};

class stObsTriggerCB : public gfCallback {

    char _spacer[8];

    virtual ~stObsTriggerCB();
    virtual gfArea* getAreaPointer();
    virtual bool getAreaID(int* areaID);
    virtual void setAreaSleep(bool isSleep);
};

class stObsTriggerArea : public stObsTriggerCB {

    gfArea* area;
    GimmickAreaData gimmickAreaData;

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