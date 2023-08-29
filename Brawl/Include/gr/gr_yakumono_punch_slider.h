#pragma once

#include <StaticAssert.h>
#include <gr/gr_gimmick_motion_path.h>
#include <gr/gr_yakumono.h>
#include <st/st_trigger.h>

struct grGimmickPunchSliderData {
    grGimmickMotionPathData m_motionPathData;
    grGimmickMotionPathData m_sliderPathData;
    grGimmick::HitData m_hitData;
    char _48[4];
    grGimmick::AttackData m_attackData;
    char _140[8];
    float m_148;
    float m_152;
    float m_156;
    float m_160;
    float m_164;
    float m_168;
    float m_difficultyMotionRatios[15];
    stTriggerData m_triggerData;
    char _232[12];
    u8 m_mdlIndex;
    char _249[3];
    char m_ballNodeName[32];
    char _284[4];
};
static_assert(sizeof(grGimmickPunchSliderData) == 288, "Class is wrong size!");

class grYakumonoPunchSlider : public grYakumono {
protected:
    grGimmickMotionPath* m_sliderMotionPath;
    grGimmickPunchSliderData* m_sliderData;
    u8 m_280;
    char _281[3];
    int m_ballNodeIndex;
    int m_polyGlowNodeIndex;
    int m_292;
    char _296[32];
    soCollisionHitData m_hitData;
    soCollisionHitPartsInfo m_hitPartsInfo;
    ykHitGroupInfo m_hitGroupsInfo;
    ykData m_ykData;

public:
    grYakumonoPunchSlider(const char* taskName);
    virtual ~grYakumonoPunchSlider();
    virtual void update(float deltaFrame);
    virtual void startup(gfArchive* archive, u32 unk1, u32 unk2);
    virtual void onDamage(int index, soDamage* damage, soDamageAttackerInfo* attackerInfo);
    virtual void onInflict(soCollisionLog* collisionLog, u32 unk2, float power);
    virtual void updateMove(float deltaFrame);
    virtual void createMotionPath();
    virtual void setCulcCallback(gfArchive* archive);
};
static_assert(sizeof(grYakumonoPunchSlider) == 452, "Class is wrong size!");
