#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <gr/gr_yakumono.h>

struct grGimmickCatapultData {
    grGimmickMotionPathData m_motionPathData;
    char _8[24];
    Vec2f m_areaOffsetPos;
    Vec2f m_areaRange;
    float m_framesBeforeStartMove;
    float m_52;
    float m_56;
    float m_vector;
    char _64[16];
    u8 m_mdlIndex;
    bool m_isFaceLeft;
    bool m_useNoHelperWarp;
    char _82[1];

    STATIC_CHECK(sizeof(grGimmickCatapultData) == 84)
};

class grGimmickCatapult : public grYakumono {

protected:
    grGimmickCatapultData* m_catapultData;
    grGimmickMotionPath* m_motionPath;
    u8 m_state;
    char m_345[3];
    float m_frameCount;
    char m_352[8];
    int m_360;
    int m_364;
    soAreaData m_areaData;
    soAreaInit m_areaInit;
    ykAreaData m_ykData;

public:
    grGimmickCatapult(char* taskName) : grYakumono(taskName){
        m_motionPath = NULL;
        m_state = 0;
        m_frameCount = 0.0;
        m_ykData.m_numHitGroups = 0;
        m_ykData.m_hitGroupsInfo = NULL;
        m_360 = -1;
        m_364 = -1;
    };
    virtual void processFixPosition();
    virtual void update(float deltaFrame);
    virtual void startup(gfArchive* archive, u32 unk1, u32 unk2);
    virtual void onGimmickEvent(soGimmickEventInfo* eventInfo, int* taskId);
    virtual ~grGimmickCatapult();

    void presentFighterPosEvent();

    static grGimmickCatapult* create(int mdlIndex, char* taskName);

    STATIC_CHECK(sizeof(grGimmickCatapult) == 420)
};