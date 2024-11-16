#pragma once

#include <StaticAssert.h>
#include <gf/gf_area.h>
#include <gf/gf_callback.h>
#include <mt/mt_vector.h>
#include <memory.h>
#include <types.h>

struct stTriggerData {
    enum KeepKind {
        Keep_None = 0x0,
        Keep_Stage = 0x1,
        Keep_Global = 0x2
    };

    unsigned short m_triggerId;
    int _padding : 7;
    bool m_isValid : 1;
    KeepKind m_keepKind : 8;
};
static_assert(sizeof(stTriggerData) == 4, "Class is wrong size!");

struct stSimpleAreaData {
    bool m_useTwoBoundingPoints;
    char _1[3];
    Vec2f m_pos1;
    Vec2f m_pos2;
};

struct grAdventureTruckReactorData : public stSimpleAreaData {
    stTriggerData m_triggerData;
};
static_assert(sizeof(grAdventureTruckReactorData) == 24, "Class is wrong size!");

struct stGimmickAreaData {
    gfArea::ShapeType m_shapeType;
    int m_4;
    char _8[8];
    short m_16;
    short m_18;
    char _20[4];
    Vec2f m_offsetPos;
    Vec2f m_range;

    inline void set(Vec2f* areaPos, Vec2f* areaRange) {
        m_offsetPos = *areaPos;
        m_range = *areaRange;
    }

    inline void set(Vec2f* areaPos, Vec2f* areaRange, gfArea::ShapeType shapeType) {
        m_offsetPos = *areaPos;
        m_range = *areaRange;
        m_shapeType = shapeType;
    }
};

struct grGimmickBeltConveyorData {
    stGimmickAreaData m_areaData;
    Vec3f m_pos;
    float m_speed;
    bool m_isRight;
    char _spacer[3];
    stTriggerData m_isValidTriggerData;

    inline grGimmickBeltConveyorData() {

    };

    inline grGimmickBeltConveyorData(Vec3f* pos, float speed, bool isRight, Vec2f* areaPos, Vec2f* areaRange, gfArea::ShapeType shapeType) {
        initialize(pos, speed, isRight, areaPos, areaRange, shapeType);
    };

    inline void initialize(Vec3f* pos, float speed, bool isRight, Vec2f* areaPos, Vec2f* areaRange, gfArea::ShapeType shapeType) {
        MEMINIT(this);
        m_pos = *pos;
        m_speed = speed;
        m_isRight = isRight;
        m_areaData.set(areaPos, areaRange, shapeType);
    };
};
static_assert(sizeof(grGimmickBeltConveyorData) == 64, "Class is wrong size!");

struct grGimmickWaterData {
    stGimmickAreaData m_areaData;
    float m_swimHeight;
    bool m_canDrown;
    char _45[3];
    float m_speed;
    char m_52[4];

    inline grGimmickWaterData() {

    };

    inline grGimmickWaterData(float swimHeight, bool canDrown, float currentSpeed, Vec2f* areaPos, Vec2f* areaRange) {
        initialize(swimHeight, canDrown, currentSpeed, areaPos, areaRange);
    };

    inline void initialize(float swimHeight, bool canDrown, float currentSpeed, Vec2f* areaPos, Vec2f* areaRange) {
        MEMINIT(this);
        m_swimHeight = swimHeight;
        m_canDrown = canDrown;
        m_speed = currentSpeed;
        m_areaData.set(areaPos, areaRange);
    };

};
static_assert(sizeof(grGimmickWaterData) == 56, "Class is wrong size!");

struct grGimmickWindData {
    stGimmickAreaData m_areaData;
    Vec3f m_pos;
    float m_speed;
    float m_vector;
    stTriggerData m_isValidTriggerData;

    inline grGimmickWindData() {

    };

    inline grGimmickWindData(Vec3f* pos, float speed, float vector, Vec2f* areaPos, Vec2f* areaRange) {
        initialize(pos, speed, vector, areaPos, areaRange);
    };

    inline void initialize(Vec3f* pos, float speed, float vector, Vec2f* areaPos, Vec2f* areaRange) {
        MEMINIT(this);
        m_pos = *pos;
        m_speed = speed;
        m_vector = vector;
        m_areaData.set(areaPos, areaRange);
    };
};
static_assert(sizeof(grGimmickWindData) == 64, "Class is wrong size!");

struct grGimmickWindData2nd {
    stGimmickAreaData m_areaData;
    Vec3f m_pos;
    float m_speed;
    float m_vector;
    float m_60;
    float m_64;
    float m_68;
    u32 m_72;
};
static_assert(sizeof(grGimmickWindData2nd) == 76, "Class is wrong size!");

struct grGimmickHitPointEffectData {
    stGimmickAreaData m_areaData;
    u8 m_damage;
    bool m_isHeal;
    short m_serialHitFrame;
    stTriggerData m_isValidTriggerData;

    inline grGimmickHitPointEffectData() {

    };

    inline grGimmickHitPointEffectData(float damage, bool isHeal, short serialHitFrame, Vec2f *areaPos, Vec2f *areaRange) {
        initialize(damage, isHeal, serialHitFrame, areaPos, areaRange);
    };

    inline void initialize(float damage, bool isHeal, short serialHitFrame, Vec2f *areaPos, Vec2f *areaRange) {
        MEMINIT(this);
        m_damage = damage;
        m_isHeal = isHeal;
        m_serialHitFrame = serialHitFrame;
        m_areaData.set(areaPos, areaRange);
    };
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
    stGimmickAreaData m_gimmickAreaData;

    virtual void userProc();
    virtual ~stObsTriggerArea();
    virtual gfArea* getAreaPointer();
    virtual bool getAreaID(int* areaID);
    virtual void setAreaSleep(bool isSleep);
    virtual stGimmickAreaData* getAreaDataPointer();
    virtual void setArea(gfArea* area);

    void setDefaultGimmickAreaData(stSimpleAreaData* simpleAreaData, stGimmickAreaData* gimmickAreaData);
};

class stObsTriggerSquareHitPointEffectCB : public stObsTriggerArea {
    int m_hitPointEffectIndex;

    virtual ~stObsTriggerSquareHitPointEffectCB();

};
static_assert(sizeof(stObsTriggerSquareHitPointEffectCB) == 0x40, "Class is wrong size!");

class stObsTriggerSquareBeltConveyorCB : public stObsTriggerArea {
    int m_beltConveyorIndex;

    virtual ~stObsTriggerSquareBeltConveyorCB();
};
static_assert(sizeof(stObsTriggerSquareBeltConveyorCB) == 0x40, "Class is wrong size!");

class stObsTriggerSquareWaterCB : public stObsTriggerArea {
    int m_waterIndex;

    virtual ~stObsTriggerSquareWaterCB();
};
static_assert(sizeof(stObsTriggerSquareWaterCB) == 0x40, "Class is wrong size!");

class stObsTriggerSquareWindCB : public stObsTriggerArea {
    int m_windIndex;

    virtual ~stObsTriggerSquareWindCB();
};
static_assert(sizeof(stObsTriggerSquareWindCB) == 0x40, "Class is wrong size!");