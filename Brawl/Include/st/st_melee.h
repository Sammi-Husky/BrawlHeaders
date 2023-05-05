#pragma once

#include <st/st_common_gimmick.h>
#include <types.h>

class stMelee : public stCommonGimmick {
protected:
    // 0
    char _spacer[0x10];

    stTrigger* m_wind2ndTrigger; // +0x1C4

    grGimmickWindData2nd* m_windAreaData2nd; // +0x1C8

    // 0x18
    char _396[0xc];

public:
    stMelee(char const* name, srStageKind stageKind);
    virtual void processBegin();
    virtual void processUpdate();
    virtual void getItemGenPac(gfArchive** archive);
    virtual void getFighterStartPos(Vec3f* startPos, int fighterIndex);
    virtual void getFighterReStartPos(Vec3f* startPos, int fighterIndex);
    virtual bool createWind2ndOnly();
    virtual grGimmickWindData2nd* getWind2ndOnlyData() { return m_windAreaData2nd; } // TODO
    virtual void updateWind2ndOnly();                                                // TODO
    virtual bool isReStartSamePoint() { return true; }
    virtual void update(float deltaFrame);
    virtual void setCameraLimitRange(float unk1, float unk2, float unk3, float unk4); // TODO
    virtual void resetCameraLimitRange();                                             // TODO
    virtual bool checkChangeScene();                                                  // TODO
    virtual void resetChangeScene();                                                  // TODO
    virtual void setChangeSceneNumber(s32 n);                                         // TODO
    ~stMelee();

    void zoomInCamera();
    void zoomOutCamera(float, float);
    void setPlayerPositionIndexSerial();
    int playSeBasic(SndID id, float p2);
    void stopSeBasic(int index, float);
    void setGravityHalf();
    void setGravityNormal();

    static bool getPlayerPosition(int playerNo, Vec3f* pos);
};
static_assert(sizeof(stMelee) == 472, "Class is wrong size!");
