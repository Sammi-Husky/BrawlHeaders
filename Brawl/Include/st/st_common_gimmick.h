#pragma once

#include <st/stage.h>
#include <types.h>

class stCommonGimmick : public Stage {
protected:
    gfArchive* fileData;
    char _spacer[0x10];

public:
    stCommonGimmick(char* name, int unk1);
    void releaseArchive();
    virtual ~stCommonGimmick();
};