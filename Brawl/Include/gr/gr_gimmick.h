#pragma once

#include <gr/ground.h>
#include <gr/gr_calc_world_callback.h>
#include <snd/snd_3d_generator.h>
#include <st/st_trigger.h>

struct grGimmickMotionPathData {
    float motionRatio;
    char index;
    char field_0x5;
    char mdlIndex;
    char _padding;
};

struct grGimmickMotionPathInfo {
    gfArchive* archive;
    grGimmickMotionPathData* motionPathData;
    int field_0x8;
    int field_0xc;
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1c;
    int field_0x20;
};

struct Effect_Info {
    short field_0x0;
    short field_0x2;
    float field_0x4;
    int field_0x8;
    int field_0xc;
    int field_0x10;
    int field_0x14;
    short nodeIndex;
    short field_0x1a;
    float field_0x1c;
    float field_0x20;
    float field_0x24;
};

struct grGimmickSimpleEffectData {
    char _spacer[6];
    short nodeIndex;
    char _spacer2[4];
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

    int field_0x4;
    float field_0x8;
    bool enabled;
    bool visiblePermission;
    char _padding[2];
};

class grGimmick : public Ground {

    public:
        // 5C
        int numSndGenerators;
        // 60
        snd3DGenerator* snd3DGenerators;
        // 64
        int numSoundEffects;
        // 68
        Effect_Info* soundEffects;
        // 6C
        int numEffects;
        // 70
        Effect_Info* effects;
        // 74
        char _spacer6[8];
        // 7C
        void* gimmickData;
        // 80
        u32 unk1;
        // 84
        u32 unk2;
        // 88
        u32 unk3;
        // 8C
        grGimmickMotionPath* gimmickMotionPath;
        // 90
        grCalcWorldCallBack calcWorldCallBack;
        // A0
        char unk5;
        // A1
        char transparencyFlag;
        // A2
        char _spacer7[26];
        // BC
        grVisibleProduction* visibleProductions[4];
        // CC
        char spacer[0x40];

        grGimmick(char* taskName);
        
        virtual void processUpdate();
        virtual void renderDebug();
        virtual void update(float frameDiff);
        virtual void bindData(gfArchive* data);
        virtual void setVisibilityAttachedEffect(u32 unk1);
        virtual int setNode();
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
        virtual void createEffectVisibleProductionForExcel(grGimmickSimpleEffectData *simpleEffectData, u32* visProdIndexPtr, grVisibleProduction* visProds[]);
        virtual void setSimpleEffectVisibleProduction(); // TODO
        virtual void dbDispInvalidatedByCameraClippingSphere(); // TODO
        virtual void setTransparency(u32 unk1, u32 unk2);
        virtual char getTransparencyFlag();

        void changeMatColAnim(u32 unk1, u32 unk2);
        void changeShapeAnim(u32 unk1, u32 unk2);
        void changeTexAnim(u32 unk1, u32 unk2);
        void changeTexSrtAnim(u32 unk1, u32 unk2);
        void changeVisibleAnim(u32 unk1, u32 unk2);
        void createAttachMotionPath(grGimmickMotionPathInfo* motionPathInfo, stTriggerData* triggerData, char* nodeName);
        void createEffectWork(int numEffects);
        void createIsValidTrigger(stTriggerData* triggerData);
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
        static void getPos(Vec3f* pos, grGimmick* ground);
        static void getRot(Vec3f* rot, grGimmick* ground);
        static void getScale(Vec3f* scale, grGimmick* ground);
        void startGimmickEffect(u32 index);
        void startGimmickSE(u32 index);
        void stopGimmickEffect(u32 index);
        void stopGimmickSE(u32 index);
        void updataGimmickEffect(float unk1);
        void updataGimmickSE(float unk1);
        void updateProduction(float unk1);
};



