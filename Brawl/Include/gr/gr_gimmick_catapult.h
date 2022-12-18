#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <gr/gr_yakumono.h>

struct grGimmickCatapultData {
    grGimmickMotionPathData m_motionPathData;
    char _8[24];
    Vec2f m_areaOffsetPos;
    Vec2f m_areaRange;
    float m_48;
    float m_52;
    float m_56;
    float m_60;
    char _64[16];
    u8 m_mdlIndex;
    bool m_81;
    char _82[2];

    STATIC_CHECK(sizeof(grGimmickCatapultData) == 84)
};

class grGimmickCatapult : public grYakumono {

protected:
    grGimmickCatapultData* m_catapultData;
    grGimmickMotionPath* m_motionPath;
    u8 m_344;
    char m_345[15];
    int m_360;
    int m_364;
    soAreaData m_areaData;
    soAreaInit m_areaInit;
    ykAreaData m_ykData;

public:
    virtual void processFixPosition();
    virtual void update(float deltaFrame);
    virtual void startup(gfArchive* archive, u32 unk1, u32 unk2);
    virtual void onGimmickEvent(soGimmickEventInfo* eventInfo, int* taskId);
    virtual ~grGimmickCatapult() { };

    void presentFighterPosEvent();

    static grGimmickCatapult* create(int mdlIndex, char* taskName);

    STATIC_CHECK(sizeof(grGimmickCatapult) == 420)
};