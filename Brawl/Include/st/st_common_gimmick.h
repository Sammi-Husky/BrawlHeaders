#pragma once

#include <st/stage.h>
#include <gr/gr_gimmick_spring.h>
#include <gr/gr_gimmick_ladder.h>
#include <types.h>

class stCommonGimmick : public Stage {
public:
    gfArchive* m_fileData;
    gfArchive* m_secondaryFileData;
    char _spacer[5];
    bool m_isPaused;
    char _spacer2[2];
    gfArchive* m_commonFileData;

    stCommonGimmick(char* name, int unk1);
    virtual void processBegin();
    virtual ~stCommonGimmick();

    void releaseArchive();
    void createGimmickCollision(int collIndex, Ground* ground, gfArchive* archive);
    void createGimmickBeltConveyor2(SquareBeltConveyorGimmickAreaData* beltConveyorAreaData);
    void createGimmickLadder(grGimmickLadderData *ladderData, gfArchive *archive);
};