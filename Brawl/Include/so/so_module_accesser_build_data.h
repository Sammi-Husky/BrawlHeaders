#pragma once

#include <StaticAssert.h>
#include <so/ground/so_ground_module_impl.h>
#include <so/so_common_data_accesser.h>
#include <so/so_value_accesser.h>
#include <sr/sr_common.h>
#include <types.h>

class soModuleAccesserBuildData {
public:
    virtual u32 getMdlResId() = 0;
    virtual u32 getAnimResId() = 0;
    virtual u8 getResGroupNo() = 0;
    virtual s32 getTeam() = 0;
    virtual soMotionData* getMotionData() = 0;
    virtual soShakeData* getShakeData() = 0;
    virtual soVisibilityData* getVisibilityData() = 0;
    virtual soStatusData* getStatusData() = 0;
    virtual soGroundConditionChecker* getGroundConditionChecker() = 0;
    virtual void* getEffectNodeData() { return nullptr; }
    virtual void* getEffectEmitData() = 0;
    virtual soEffectCommonData* getEffectCommonData() = 0;
    virtual soEffectScreenData* getEffectScreenData() { return nullptr; };
    virtual void* getTerritoryParam() { return nullptr; }

    // UBFIX this function has a bug; don't dereference the pointer it
    // returns! TODO flag callers of this function, if any
    virtual s32* getTerritoryRect() {
        s32 rect[4] = { 0, 0, 0, 0 };
        return rect;
    }
    virtual void* getTargetSearchParam() { return nullptr; }
    virtual soIkData* getIkData() { return nullptr; }
    virtual s32 getModelLayerType() { return 2; }
    virtual float getModelScale() { return 1.0f; }
    virtual soParamAccesser* getParamAccesser() = 0;
    virtual s32 getAreaCategory() = 0;
    virtual void* getCameraRangeSet() = 0;
    virtual void* getCameraClipSphereSet() = 0;
    virtual void* getItemNodeData() = 0;
    virtual void* getModelExtendNodeTable() { return nullptr; }
    virtual soJostleData* getJostleData() = 0;
    virtual soPreCheckAnimCmdData* getPreCheckAnimCmdData() { return nullptr; }
    virtual Heaps::HeapType getInstanceHeap() = 0;
    virtual Heaps::HeapType getNWModelInstanceHeap() = 0;
    virtual Heaps::HeapType getNWMotionInstanceHeap() = 0;
    virtual s32 getHeapSlotNo() { return 0; }
    virtual soSoundIdExchanger* getSoundIdExchanger() {
        return &g_soSoundIdExchangerNull;
    }
    virtual float getSlopeAngleLimit() { return 20.0f; }
    virtual ~soModuleAccesserBuildData() { }
    virtual void* getAnimCmdData(u32 eventThread, s32 p2) = 0;
};
static_assert(sizeof(soModuleAccesserBuildData) == 0x4, "Class is the wrong size!");
