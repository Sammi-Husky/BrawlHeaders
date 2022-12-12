#pragma once

#include <st/stage.h>
#include <types.h>

class stCommonGimmick : public Stage {
protected:
    gfArchive* m_fileData;
    gfArchive* m_secondaryFileData;
    char _spacer[5];
    bool m_isPaused;
    char _spacer2[2];
    gfArchive* m_commonFileData;

public:
    stCommonGimmick(char* name, int unk1);
    void releaseArchive();
    virtual void processBegin();
    virtual ~stCommonGimmick();
};