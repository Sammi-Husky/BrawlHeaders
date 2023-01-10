#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <gr/gr_yakumono.h>

struct grGimmickLadderData {
    grGimmickMotionPathData m_motionPathData;
    char _8[24];
    Vec2f m_areaOffsetPos;
    Vec2f m_areaRange;
    u8 m_mdlIndex;
    char _49[1];
    u8 m_50;
    u8 m_51;
    char _52[32];
    stTrigger::TriggerData m_isValidTriggerData;
    stTrigger::TriggerData m_motionPathTriggerData;

    STATIC_CHECK(sizeof(grGimmickLadderData) == 92)
};

class grGimmickLadder : public grYakumono {
    protected:
        grGimmickLadderData* m_ladderData;
        soAreaData m_areaData;
        soAreaInit m_areaInit;
        ykAreaData m_ykData;
        char _328[24];

    public:
        grGimmickLadder(char* taskName);
        virtual void update(float deltaFrame);
        virtual void startup(gfArchive* archive, u32 unk1, u32 unk2);
        virtual void onGimmickEvent(soGimmickEventInfo* eventInfo, int* taskId);
        virtual bool disableArea();
        virtual bool setSleepArea(bool);
        virtual void setInitializeFlag();
        virtual ~grGimmickLadder();
        virtual void getUpperNode(Vec3f* pos);
        virtual void getUnderNode(Vec3f* pos);

    STATIC_CHECK(sizeof(grGimmickLadder) == 416)
};