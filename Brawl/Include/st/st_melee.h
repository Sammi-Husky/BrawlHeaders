#pragma once

#include <st/st_common_gimmick.h>
#include <types.h>

struct Gravity {
    float up;
    float down;
};

extern Gravity* g_Gravity;

class stMelee : public stCommonGimmick {
protected:
    // 0
    char _spacer[0x14];
    // 0x14
    char wndOnlyData2[0x10];

public:
    stMelee(char* name, int stageID);
    virtual void processBegin();
    virtual void processUpdate();
    virtual void getItemGenPac(gfArchive** archive);
    virtual void getFighterStartPos(Vec3f* startPos, int fighterIndex);
    virtual void getFighterReStartPos(Vec3f* startPos, int fighterIndex);
    virtual bool isReStartSamePoint();
    virtual bool createWind2ndOnly();
    virtual int getWind2ndOnlyData();           // TODO
    virtual void updateWind2ndOnly();           // TODO
    virtual void update(float deltaFrame);
    virtual void setCameraLimitRange(float unk1, float unk2, float unk3, float unk4); // TODO
    virtual void resetCameraLimitRange();                                             // TODO
    virtual void checkChangeScene();                                                  // TODO
    virtual void resetChangeScene();                                                  // TODO
    virtual void setChangeSceneNumber();                                              // TODO
    ~stMelee();

    void zoomInCamera();
    void zoomOutCamera(float, float);

    STATIC_CHECK(sizeof(stMelee) == 472)
};