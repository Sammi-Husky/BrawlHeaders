#pragma once

#include <gr/gr_gimmick.h>

class grGimmickMotionPath : public grGimmick {

public:
    char _spacer[4];
    float m_frame;
    char _spacer2[12];
    unsigned int m_frameCount;
    grGimmickMotionPathData* m_motionPathData;
    char _spacer3[20];
    int m_nodeIndex;
    char m_nodeName[32];

    grGimmickMotionPath(const char* taskName, const char* nodeName);
    virtual void processAnim();
    virtual void loadGroundData(u32 unk1, u32 unk2, u32 unk3);
    virtual int getModelCount();
    virtual void startup(gfArchive* data, u32 unk1, u32 unk2);
    virtual void update(float deltaFrame);
    virtual ~grGimmickMotionPath();

    virtual bool isMoveEnd();
    virtual bool isReturnEnd();
    virtual void setFrameModelAnim();
    virtual void clearFrame();

    static grGimmickMotionPath* create(int mdlIndex, const char* nodeName, const char* taskName);

    void startMove();
    void setFrameUpdate(float);
    void setFrame(float frame);
    void applyEndFrame();
    float getFrame();
    bool isEndFrame();
    bool isStartFrame();
    void getTRS(Vec3f* pos, Vec3f* rotation, Vec3f* scale);
    void stopStartSE();
};