#pragma once

#include <ft/ft_fighter_build_data.h>
#include <so/resource/so_resource_module_impl.h>
#include <types.h>

class soModuleAccesser;

////////////////////////////////////////
// soHeapModuleBuilder
////////////////////////////////////////

template <typename T>
class soHeapModuleBuildConfig {
public:
    typedef T ModuleType;
};

template <typename BC>
class soHeapModuleBuilder {
    typename BC::ModuleType m_heapModule;
public:
    soHeapModuleBuilder(const ftFighterBuildData& fbd) :
        m_heapModule(
            fbd.getInstanceHeap(),
            fbd.getNWModelInstanceHeap(),
            fbd.getNWMotionInstanceHeap(),
            fbd.getHeapSlotNo()
        ) { }
};

////////////////////////////////////////
// soParamCustomizeModuleBuilder
////////////////////////////////////////

template <typename T>
class soParamCustomizeModuleBuildConfig {
public:
    typedef T ModuleType;
};

template <typename BC>
class soParamCustomizeModuleBuilder {
    typename BC::ModuleType m_paramCustomizeModule;
public:
    soParamCustomizeModuleBuilder(soModuleAccesser* accsr) :
        m_paramCustomizeModule(accsr) { }
};

////////////////////////////////////////
// soResourceModuleBuilder
////////////////////////////////////////

template <u32 M, typename I, typename T>
class soResourceModuleBuildConfig {
public:
    enum { ManagerId = M };
    typedef I IdAccesserType;
    typedef T ModuleType;
};

template <u32 M, typename I, typename T>
class soResourceModuleBuildConfigDynamic {
public:
    enum { ManagerId = M };
    typedef I IdAccesserType;
    typedef T ModuleType;
};

class soResourceModuleBuildConfigNull { };

template <typename BC>
class soResourceModuleBuilder {
    typename BC::IdAccesserType m_idAccsr;
    typename BC::ModuleType m_resourceModule;
public:
    static soResourceModule* getModule(soResourceModuleBuilder* b) {
        return &b->m_resourceModule;
    }

    soResourceModuleBuilder(u32 mdlResId, u32 anmResId, u8 resGrpNo, soModuleAccesser* accsr) :
        m_idAccsr(accsr), m_resourceModule(BC::ManagerId, &m_idAccsr, resGrpNo) { }
};

template <u32 M, typename I, typename T>
class soResourceModuleBuilder<soResourceModuleBuildConfig<M, I, T> > {
    I m_idAccsr;
    T m_resourceModule;
public:
    static soResourceModule* getModule(soResourceModuleBuilder* b) {
        return &b->m_resourceModule;
    }

    soResourceModuleBuilder(u32 mdlResId, u32 anmResId, u8 resGrpNo, soModuleAccesser* accsr) :
        m_idAccsr(mdlResId, mdlResId, anmResId), m_resourceModule(M, &m_idAccsr, resGrpNo) { }
};

template <>
class soResourceModuleBuilder<soResourceModuleBuildConfigNull> {
public:
    soResourceModuleBuilder(u32 mdlResId, u32 anmResId, u8 resGrpNo, soModuleAccesser* accsr) { }

    static soResourceModule* getModule(soResourceModuleBuilder* b) {
        return &g_soResourceModuleNull;
    }
};
