#pragma once

#include <StaticAssert.h>
#include <ft/ft_common_data_accesser.h>
#include <ft/ft_entry.h>
#include <ft/ft_sound_id_exchanger_impl.h>
#include <so/ground/so_ground_module_impl.h>
#include <so/so_common_data_accesser.h>
#include <so/so_module_accesser_build_data.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <sr/sr_common.h>
#include <types.h>

class ftFighterBuildData : public soModuleAccesserBuildData {
    s32 m_entryId;
    ftKind m_kind;
    ftData* m_ftData;
    u8 m_resGroupNo;
    s32 m_team;
    soModuleAccesser* m_moduleAccsr;
    void* m_cameraRangeSet;
    void* m_cameraClipSphereSet;
    Heaps::HeapType m_instHeap;
    Heaps::HeapType m_nwModelInstHeap;
    Heaps::HeapType m_nwMotionInstHeap;
public:
    ftFighterBuildData(s32 entryId, ftKind kind, Heaps::HeapType instHeap,
                       Heaps::HeapType nwModelInstHeap,
                       Heaps::HeapType nwMotionInstHeap,
                       s8 resGroupNo, soModuleAccesser* acc,
                       s32 team, void* cameraRangeSet,
                       void* cameraClipSphereSet);

    virtual u32 getMdlResId();
    virtual u32 getAnimResId();
    virtual u8 getResGroupNo();
    virtual ftMotionData* getMotionData();
    virtual ftShakeData* getShakeData();
    virtual ftVisibilityData* getVisibilityData();
    virtual ftStatusData* getStatusData();
    virtual soGroundConditionChecker* getGroundConditionChecker();
    virtual void* getEffectNodeData();
    virtual void* getEffectEmitData();
    virtual ftEffectCommonData* getEffectCommonData();
    virtual ftEffectScreenData* getEffectScreenData();
    virtual ftIkData* getIkData();
    virtual float getModelScale();
    virtual soParamAccesser* getParamAccesser();
    virtual s32 getAreaCategory();
    virtual void* getCameraRangeSet();
    virtual void* getCameraClipSphereSet();
    virtual void* getItemNodeData();
    virtual void* getModelExtendNodeTable();
    virtual ftJostleData* getJostleData();
    virtual ftPreCheckAnimCmdData* getPreCheckAnimCmdData();
    virtual ~ftFighterBuildData() { }
    virtual s32 getTeam() { return m_team; }
    virtual Heaps::HeapType getInstanceHeap() { return m_instHeap; }
    virtual Heaps::HeapType getNWModelInstanceHeap() { return m_nwModelInstHeap; }
    virtual Heaps::HeapType getNWMotionInstanceHeap() { return m_nwMotionInstHeap; }
    virtual s32 getHeapSlotNo();
    virtual ftSoundIdExchangerImpl* getSoundIdExchanger();
    virtual float getSlopeAngleLimit();
    virtual void* getAnimCmdData(u32 eventThread, s32 p2);

    soAnimCmdDisguiseList* getAnimCmdDisguiseList(bool p1, s32 actionType);
};
static_assert(sizeof(ftFighterBuildData) == 0x30, "Class is the wrong size!");
