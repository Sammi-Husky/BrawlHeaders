#pragma once

#include <gr/gr_gimmick_catapult.h>
#include <gr/gr_gimmick_ladder.h>
#include <gr/gr_gimmick_spring.h>
#include <st/stage.h>
#include <types.h>

class stCommonGimmick : public Stage {
public:
    gfArchive* m_fileData; // 0x1A0
    gfArchive* m_secondaryFileData; // 0x1A4
    gfArchive* unk1A8; // 0x1A8
    char _spacer[1];
    bool m_isPaused;
    char _spacer2[2];
    gfArchive* m_commonFileData;

    stCommonGimmick(const char* name, srStageKind stageKind);
    virtual void processBegin();
    virtual ~stCommonGimmick();

    void releaseArchive();
    void createGimmickCollision(int collIndex, Ground* ground, gfArchive* archive);
    bool createGimmickBeltConveyor2(grGimmickBeltConveyorData* beltConveyorAreaData);
    bool createGimmickWaterArea(grGimmickWaterData* waterAreaData);
    bool createGimmickWind2(grGimmickWindData* windAreaData);
    bool createGimmickHitPointEffectArea(grGimmickHitPointEffectData* hitPointEffectData);
    grGimmickLadder* createGimmickLadder(grGimmickLadderData* ladderData, gfArchive* archive);
    grGimmickCatapult* createGimmickCatapult(grGimmickCatapultData* catapultData, gfArchive* archive);
};