#pragma once

#include <StaticAssert.h>
#include <gf/gf_area.h>
#include <gf/gf_callback.h>
#include <mt/mt_vector.h>
#include <types.h>

struct stTriggerData {
    unsigned short m_triggerId;
    int _padding : 7;
    bool m_isValidFlag : 1;
    char m_unk2;
};
static_assert(sizeof(stTriggerData) == 4, "Class is wrong size!");

struct SimpleAreaData {
    bool m_useTwoBoundingPoints;
    char _1[3];
    Vec2f m_pos1;
    Vec2f m_pos2;
};

struct grAdventureTruckReactorData : public SimpleAreaData {
    stTriggerData m_triggerData;
};
static_assert(sizeof(grAdventureTruckReactorData) == 24, "Class is wrong size!");

struct GimmickAreaData {
    int m_0;
    int m_4;
    char _8[8];
    short m_16;
    short m_18;
    char _20[4];
    Vec2f m_pos;
    Vec2f m_range;
};

struct grGimmickBeltConveyorData : GimmickAreaData {
    Vec3f m_conveyorPos;
    float m_speed;
    bool m_isRightDirection;
    char _spacer[3];
    stTriggerData m_isValidTriggerData;
};
static_assert(sizeof(grGimmickBeltConveyorData) == 64, "Class is wrong size!");

struct grGimmickWaterData : GimmickAreaData {
    float m_swimHeight;
    bool m_canDrown;
    char _45[3];
    float m_currentSpeed;
    char m_52[4];
};
static_assert(sizeof(grGimmickWaterData) == 56, "Class is wrong size!");

struct grGimmickWindData : GimmickAreaData {
    Vec3f m_windPos;
    float m_strength;
    float m_angle;
    stTriggerData m_isValidTriggerData;
};
static_assert(sizeof(grGimmickWindData) == 64, "Class is wrong size!");

struct grGimmickWindData2nd : GimmickAreaData {
    char _40[12];
    float m_windStrength;
    float m_horizontalWindRotation;
    float m_verticalWindRotation;
    float m_64;
    float m_68;
    u32 m_72;
};
static_assert(sizeof(grGimmickWindData2nd) == 76, "Class is wrong size!");

struct grGimmickHitPointEffectData : GimmickAreaData {
    u8 m_damage;
    bool m_isHeal;
    short m_detectionRate;
    stTriggerData m_isValidTriggerData;
};
static_assert(sizeof(grGimmickHitPointEffectData) == 48, "Class is wrong size!");

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

    void setDefaultGimmickAreaData(SimpleAreaData* simpleAreaData, GimmickAreaData* gimmickAreaData);
};

class stObsTriggerSquareBeltConveyorCB : public stObsTriggerArea {
    char _spacer[4];

    virtual void userProc();
    virtual ~stObsTriggerSquareBeltConveyorCB();
};
static_assert(sizeof(stObsTriggerSquareBeltConveyorCB) == 0x40, "Class is wrong size!");