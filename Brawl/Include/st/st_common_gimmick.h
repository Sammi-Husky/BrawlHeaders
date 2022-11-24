#pragma once

#include <st/stage.h>
#include <types.h>

class stCommonGimmick : public Stage {
protected:
    gfArchive* fileData;
    gfArchive* secondaryFileData;
    char _spacer[5];
    bool isPaused;
    char _spacer2[2];
    gfArchive* commonFileData;

public:
    stCommonGimmick(char* name, int unk1);
    void releaseArchive();
    virtual void processBegin();
    virtual ~stCommonGimmick();
};