#pragma once

#include <gr/ground.h>
#include <st/st_trigger.h>

struct grGimmickMotionPathData {
    float motionRatio;
    char index;
    char field_0x5;
    char mdlIndex;
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

struct grGimmickSimpleEffectData {
    char _spacer[6];
    short nodeIndex;
    char _spacer2[4];
};

class grGimmick : public Ground {
    protected:
        char spacer[0x48];
    public:
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
        virtual void updateCallback(u32 unk1);
        virtual void fixedPosition(float unk1);
        virtual void setTgtNode(char* unk1);
        virtual u32 getTgtNode();
        virtual void setGimmickData(void* gimmickData);
        virtual void* getGimmickData();
        virtual void changeNodeAnim(u32 unk1, u32 unk2);
        virtual void createFadeVisibleProduction(float unk);
        virtual void createSoundEffectVisibleProductionForExcel(u32 unk1, u32 unk2, u32 unk3);
        virtual void createEffectVisibleProductionForExcel(grGimmickSimpleEffectData *simpleEffectData, u32 unk2, u32 unk3);
        virtual void setSimpleEffectVisibleProduction(); // TODO
        virtual void dbDispInvalidatedByCameraClippingSphere(); // TODO
        virtual void setTransparency(u32 unk1, u32 unk2);
        virtual char getTransparencyFlag();

        void changeMatColAnim(u32 unk1, u32 unk2);
        void changeShapeAnim(u32 unk1, u32 unk2);
        void changeTexAnim(u32 unk1, u32 unk2);
        void changeTexSrtAnim(u32 unk1, u32 unk2);
        void changeVisibleAnim(u32 unk1, u32 unk2);
        void createAttachMotionPath(grGimmickMotionPathInfo* motionPathInfo, TriggerData* triggerData, char* nodeName);
        void createEffectWork(int unk1);
        void createIsValidTrigger(short* unk1);
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
        void setPosGimmickEffect(int unk1, Vec3f* pos);
        void setPRSGimmickEffect(u32 index);
        void setRot(Vec3f* rot);
        void setRot(float x, float y, float z);
        void setScale(Vec3f* scale);
        void setScale(float x, float y, float z);
        static void getPos(Vec3f* pos, grGimmick* ground);
        static void getRot(Vec3f* rot, grGimmick* ground);
        static void getScale(Vec3f* scale, grGimmick* ground);
        void startGimmickEffect(u32 unk1);
        void startGimmickSE(u32 unk1);
        void stopGimmickEffect(u32 unk1);
        void stopGimmickSE(u32 unk1);
        void updataGimmickEffect(float unk1);
        void updataGimmickSE(float unk1);
        void updateProduction(float unk1);
};



