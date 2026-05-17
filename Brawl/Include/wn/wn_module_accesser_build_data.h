#pragma once

#include <StaticAssert.h>
#include <so/ground/so_ground_module_impl.h>
#include <so/so_common_data_accesser.h>
#include <so/so_module_accesser_build_data.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <sr/sr_common.h>
#include <types.h>

class wnModuleAccesserBuildData : public soModuleAccesserBuildData {
public:
    // TODO: add missing params
    wnModuleAccesserBuildData(s32 entryId, s32 kind, Heaps::HeapType instHeap,
                       Heaps::HeapType nwModelInstHeap,
                       Heaps::HeapType nwMotionInstHeap,
                       s8 resGroupNo, soModuleAccesser* acc,
                       s32 team, void* cameraRangeSet,
                       void* cameraClipSphereSet);

    virtual u32 getMdlResId();
    virtual u32 getAnimResId();
    virtual u8 getResGroupNo();
    virtual s32 getTeam();
    virtual wnMotionData* getMotionData();
    virtual wnShakeData* getShakeData();
    virtual wnVisibilityData* getVisibilityData();
    virtual wnStatusData* getStatusData();
    virtual soGroundConditionChecker* getGroundConditionChecker();
    virtual void* getEffectEmitData();
    virtual wnEffectCommonData* getEffectCommonData();
    virtual soParamAccesser* getParamAccesser();
    virtual s32 getAreaCategory();
    virtual void* getCameraRangeSet();
    virtual void* getCameraClipSphereSet();
    virtual void* getItemNodeData();
    virtual wnJostleData* getJostleData();
    virtual Heaps::HeapType getInstanceHeap();
    virtual Heaps::HeapType getNWMotionInstanceHeap();
    virtual Heaps::HeapType getNWModelInstanceHeap();
    virtual ~wnModuleAccesserBuildData();
    virtual void* getAnimCmdData(u32 eventThread, s32 p2);
};
// TODO: size
