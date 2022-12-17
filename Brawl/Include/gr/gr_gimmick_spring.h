#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <gr/gr_yakumono.h>

struct grGimmickSpringData {
    grGimmickMotionPathData motionPathData;
    char _8[24];
    Vec2f m_areaOffsetPos;
    Vec2f m_areaRange;
    Vec2f m_pos;
    float m_rot;
    float m_60;
    char _64[8];
    u8 m_mdlIndex;
    u8 m_collIndex;
    char _74[2];
    stTrigger::TriggerData m_triggerData;

    STATIC_CHECK(sizeof(grGimmickSpringData) == 80)
};

class grGimmickSpring : public grYakumono {
    grGimmickSpringData* m_springData;
    char _276[20];
    soAreaData m_areaData;
    soAreaInit m_areaInit;
    ykAreaData m_ykData;

    virtual void update(float deltaFrame);
    virtual void startup(gfArchive* archive, u32 unk1, u32 unk2);
    virtual void onGimmickEvent(soGimmickEventInfo* eventInfo, int* taskId);
    virtual ~grGimmickSpring() { };
    virtual void setMotionOff();
    virtual void setInitializeFlag();
    virtual bool setSleepArea(bool);
    virtual bool disableArea();

    void getTopNode(Vec3f* pos);
    void presentPosEvent();
    void presentShootEvent();
    
    STATIC_CHECK(sizeof(grGimmickSpring) == 412)
};