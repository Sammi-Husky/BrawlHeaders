#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <gr/gr_yakumono.h>

struct grGimmickSpringData {
public:
    grGimmickMotionPathData m_motionPathData;
    char _8[24];
    Vec2f m_areaOffsetPos;
    Vec2f m_areaRange;
    Vec2f m_pos;
    float m_rot;
    float m_bounce;
    char _64[8];
    u8 m_mdlIndex;
    u8 m_collIndex;
    char _74[2];
    stTrigger::TriggerData m_triggerData;

    STATIC_CHECK(sizeof(grGimmickSpringData) == 80)
};

class grGimmickSpring : public grYakumono {

protected:
    enum State {
        State_Rest = 0x0,
        State_On = 0x1,
        State_Off = 0x2
    };

    grGimmickSpringData* m_springData;
    int m_276;
    State m_state : 8;
    char _281[3];
    float m_animFrame;
    u32 m_animOnLength;
    u32 m_animOffLength;
    soAreaData m_areaData;
    soAreaInit m_areaInit;
    ykAreaData m_ykData;

public:
    grGimmickSpring(char* taskName);
    virtual void update(float deltaFrame);
    virtual void startup(gfArchive* archive, u32 unk1, u32 unk2);
    virtual void onGimmickEvent(soGimmickEventInfo* eventInfo, int* taskId);
    virtual ~grGimmickSpring() { };
    virtual void setMotionOff();
    virtual void setInitializeFlag();
    virtual bool setSleepArea(bool);
    virtual bool disableArea();
    virtual void getTopNode(Vec3f* pos);

    void presentPosEvent();
    void presentShootEvent();

    STATIC_CHECK(sizeof(grGimmickSpring) == 412)
};