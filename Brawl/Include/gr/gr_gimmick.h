#pragma once

#include <StaticAssert.h>
#include <gr/gr_calc_world_callback.h>
#include <gr/ground.h>
#include <snd/snd_3d_generator.h>
#include <st/st_trigger.h>

struct grGimmickMotionPathData {
    float m_motionRatio;
    char m_index;
    char m_0x5;
    char m_mdlIndex;
    char _padding;
};

struct grGimmickMotionPathInfo {
    gfArchive* m_archive;
    grGimmickMotionPathData* m_motionPathData;
    int m_0x8;
    int m_0xc;
    int m_0x10;
    int m_0x14;
    int m_0x18;
    int m_0x1c;
    int m_0x20;
};

struct Effect_Info {
    short m_0x0;
    short m_0x2;
    float m_0x4;
    int m_0x8;
    int m_id;
    int m_0x10;
    int m_0x14;
    short m_nodeIndex;
    short m_0x1a;
    float m_0x1c;
    float m_0x20;
    float m_0x24;
};

struct grGimmickSimpleEffectData {
    unsigned int m_id;
    short m_0x4;
    short m_nodeIndex;
    short m_0x8;
    short m_0xc;
};

class grGimmickMotionPath;

class grVisibleProduction {
    virtual ~grVisibleProduction();
    virtual void updateProduct();
    virtual void initialize();
    virtual void remove();
    virtual void setStart();
    virtual void productFlowStandby();
    virtual void productFlowStart();
    virtual void productFlowProducing();
    virtual void productFlowEnd();
    virtual void setEnable(bool enable);
    virtual bool isEnable();
    virtual bool isFinished();
    virtual bool isStandby();
    virtual bool isExecuting();
    virtual bool isVisiblePermission();
    virtual void setForcedEnding();

    int m_0x4;
    float m_0x8;
    bool m_enabled;
    bool m_visiblePermission;
    char _padding[2];
};

class grGimmick : public Ground {

public:
    // 5C
    int m_numSndGenerators;
    // 60
    snd3DGenerator* m_snd3DGenerators;
    // 64
    int m_numSoundEffects;
    // 68
    Effect_Info* m_soundEffects;
    // 6C
    int m_numEffects;
    // 70
    Effect_Info* m_effects;
    // 74
    char _spacer6[8];
    // 7C
    void* m_gimmickData;
    // 80
    u32 m_unk1;
    // 84
    int m_nodeIndex;
    // 88
    bool m_isUpdate;
    // 89
    char unk3[3];
    // 8C
    grGimmickMotionPath* m_gimmickMotionPath;
    // 90
    grCalcWorldCallBack m_calcWorldCallBack;
    // A0
    char m_unk5;
    // A1
    bool m_transparencyFlag;
    // A2
    char _spacer7[2];
    // A4
    union {
        struct {
            u32 m_transparencySettingPadding : 27;
            bool m_transparencySetting4 : 1;
            bool m_transparencySetting3 : 1;
            bool m_transparencySetting2 : 1;
            bool m_transparencySetting1 : 1;
            bool m_transparencySetting0 : 1;
        };
        u32 m_transparencySettings;
    };
    // A8
    char _spacer8[20];
    // BC
    grVisibleProduction* m_visibleProductions[4];
    // CC
    char _spacer9[0x40];

    grGimmick(char* taskName);

    virtual void processUpdate();
    virtual void renderDebug();
    virtual void update(float deltaFrame);
    virtual void bindData(gfArchive* data);
    virtual void setVisibilityAttachedEffect(u32 unk1);
    virtual bool setNode();
    virtual void setMotionRatio(float ratio);
    virtual void startup(gfArchive* data, u32 unk1, u32 unk2);
    virtual ~grGimmick();

    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag(char flag);
    virtual void updateCallback(u32 index);
    virtual void fixedPosition(float unk1);
    virtual void setTgtNode(char* unk1);
    virtual u32 getTgtNode();
    virtual void setGimmickData(void* gimmickData);
    virtual void* getGimmickData();
    virtual void changeNodeAnim(u32 unk1, u32 unk2);
    virtual void createFadeVisibleProduction(float unk);
    virtual void createSoundEffectVisibleProductionForExcel(u32 unk1, u32 unk2, u32 unk3);
    virtual void createEffectVisibleProductionForExcel(grGimmickSimpleEffectData* simpleEffectData, u32* visProdIndexPtr, grVisibleProduction* visProds[]);
    virtual void setSimpleEffectVisibleProduction();        // TODO
    virtual void dbDispInvalidatedByCameraClippingSphere(); // TODO
    virtual void setTransparency(u32 unk1, u32 unk2);
    virtual char getTransparencyFlag();

    void changeMatColAnim(u32 unk1, u32 unk2);
    void changeShapeAnim(u32 unk1, u32 unk2);
    void changeTexAnim(u32 unk1, u32 unk2);
    void changeTexSrtAnim(u32 unk1, u32 unk2);
    void changeVisibleAnim(u32 unk1, u32 unk2);
    void createAttachMotionPath(grGimmickMotionPathInfo* motionPathInfo, stTrigger::TriggerData* triggerData, char* nodeName);
    void createEffectWork(int numEffects);
    void createIsValidTrigger(stTrigger::TriggerData* triggerData);
    void createSimpleEffectData(grGimmickSimpleEffectData* simpleEffectData, u32 unk2, char* nodeName);
    void createSoundWork(u32 unk1, u32 unk2);
    u32 getMaterialColor(int* unk1, char* unk2, u32* sceneModelIndex);
    u32 getMaterialTevColor(int* unk1, char* unk2, u32* sceneModelIndex);
    void getMatrix(Matrix* matrix);
    void makeCalcuCallback(u32 numCallbackData, HeapType heapType);
    void setAttachPathdataFrame(float frame);
    void setCalcuCallbackRoot(u32 unk1);
    void setMaterialAlpha(char* unk1, u32 unk2);
    void setMaterialColor(u32* unk1, char* unk2, u32* unk3, u32* sceneModelIndex);
    void setMaterialTevColor(u32* unk1, char* unk2, u32* unk3, u32* sceneModelIndex);
    void setMatrix(Matrix* matrix);
    void setPos(Matrix* matrix);
    void setPos(Vec3f* pos);
    void setPos(float x, float y, float z);
    void setPosGimmickEffect(u32 index, Vec3f* pos);
    void setPRSGimmickEffect(u32 index);
    void setRot(Vec3f* rot);
    void setRot(float x, float y, float z);
    void setScale(Vec3f* scale);
    void setScale(float x, float y, float z);
    Vec3f getPos();
    Vec3f getRot();
    Vec3f getScale();
    void startGimmickEffect(u32 index);
    void startGimmickSE(u32 index);
    void stopGimmickEffect(u32 index);
    void stopGimmickSE(u32 index);
    void updataGimmickEffect(float unk1);
    void updataGimmickSE(float unk1);
    void updateProduction(float unk1);

    STATIC_CHECK(sizeof(grGimmick) == 0x14c)
};
