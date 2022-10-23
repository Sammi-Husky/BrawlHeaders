#pragma once

#include <gr/gr_gimmick.h>

class grGimmickMotionPath : public grGimmick
{

    char _spacer[4];
    float frame;
    char _spacer2[12];
    unsigned int frameCount;
    grGimmickMotionPathData *motionPathData;
    char _spacer3[20];
    int nodeIndex;
    char nodeName[32];

public:
    grGimmickMotionPath(char *taskName, char *nodeName);
    virtual void processAnim();
    virtual void loadGroundData(u32 unk1, u32 unk2, u32 unk3);
    virtual int getModelCount();
    virtual void startup(gfArchive *data, u32 unk1, u32 unk2);
    virtual void update(float deltaFrame);
    virtual ~grGimmickMotionPath();

    virtual bool isMoveEnd();
    virtual bool isReturnEnd();
    virtual void setFrameModelAnim();
    virtual void clearFrame();

    void setFrameUpdate(float);
};