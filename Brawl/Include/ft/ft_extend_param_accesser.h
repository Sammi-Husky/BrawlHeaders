#pragma once

#include <StaticAssert.h>
#include <gm/gm_lib.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <types.h>

class ftExtendParamAccesser : public soParamAccesser {
    Fighters::ftFighterKind m_kind;
public:
    ftExtendParamAccesser(Fighters::ftFighterKind kind);
    static ftExtendParamAccesser* getAccesser(Fighters::ftFighterKind kind);
    static bool isExistAccesser(Fighters::ftFighterKind kind);

    virtual ~ftExtendParamAccesser();
    virtual float getParamFloat(soModuleAccesser* moduleAccesser, s32 p2, s32 p3) = 0;
    virtual s32 getParamInt(soModuleAccesser* moduleAccesser, s32 p2, s32 p3) = 0;
    virtual void* getParamIndefinite(soModuleAccesser* moduleAccesser, s32 p2, s32 p3) { return nullptr; }
    virtual void setup() = 0;
};
static_assert(sizeof(ftExtendParamAccesser) == 0x10, "Class is the wrong size!");

// Note: T1 and T3 always equal 3999 and 24999 and have unknown purpose
template<u32 T1, u32 NumFloats, u32 T3, u32 NumInts>
class ftExtendParamAccesserEx : public ftExtendParamAccesser {
    static const s32 NumVariations = 2;
    static const s32 OffsetFloat = 4000;
    static const s32 OffsetInt = 24000;

    float* m_floats[NumVariations][NumFloats+1];
    int* m_ints[NumVariations][NumInts+1];
public:
    ftExtendParamAccesserEx(Fighters::ftFighterKind kind)
        : ftExtendParamAccesser(kind) { }
    virtual ~ftExtendParamAccesserEx() { }
    virtual float getParamFloat(soModuleAccesser* moduleAccesser, s32 p2, s32 p3) {
        return m_floats[soValueAccesser::getValueVariation()][p2-OffsetFloat][p3];
    }
    virtual s32 getParamInt(soModuleAccesser* moduleAccesser, s32 p2, s32 p3) {
        return m_ints[soValueAccesser::getValueVariation()][p2-OffsetInt][p3];
    }
    virtual void* getParamIndefinite(soModuleAccesser* moduleAccesser, s32 p2, s32 p3) {
        return nullptr;
    }
    virtual void setup() { }
};
