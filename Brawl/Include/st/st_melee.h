#pragma once

#include <st/st_common_gimmick.h>
#include <types.h>

struct Gravity {
    float m_up;
    float m_down;
};

extern Gravity* g_Gravity;

class stMelee : public stCommonGimmick {
protected:
    // 0
    char _spacer[0x10];

    stTrigger* m_wind2ndTrigger;

    grGimmickWindData2nd* m_windAreaData2nd;

    // 0x18
    char wndOnlyData2[0xc];

public:
    stMelee(char const* name, int stageID);
    virtual void processBegin();
    virtual void processUpdate();
    virtual void getItemGenPac(gfArchive** archive);
    virtual void getFighterStartPos(Vec3f* startPos, int fighterIndex);
    virtual void getFighterReStartPos(Vec3f* startPos, int fighterIndex);
    virtual bool createWind2ndOnly();
    virtual int getWind2ndOnlyData() { return (int) m_windAreaData2nd; } // TODO
    virtual void updateWind2ndOnly();           // TODO
    virtual bool isReStartSamePoint() { return true; }
    virtual void update(float deltaFrame);
    virtual void setCameraLimitRange(float unk1, float unk2, float unk3, float unk4); // TODO
    virtual void resetCameraLimitRange();                                             // TODO
    virtual void checkChangeScene();                                                  // TODO
    virtual void resetChangeScene();                                                  // TODO
    virtual void setChangeSceneNumber();                                              // TODO
    ~stMelee();

    void zoomInCamera();
    void zoomOutCamera(float, float);
    void setPlayerPositionIndexSerial();

    STATIC_CHECK(sizeof(stMelee) == 472)
};
