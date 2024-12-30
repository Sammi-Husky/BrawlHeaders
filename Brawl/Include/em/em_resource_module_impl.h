#pragma once

#include <em/em_create.h>
#include <so/resource/so_resource_module_impl.h>
#include <types.h>

// TODO: Determine size
class emResourceModuleImpl : public soResourceModuleImpl {
    u8 unk18[0x14];
    void* unk2C;
    u8 unk30[0x4];
    void* unk34;
public:
    template<typename T>
    static void ModifyExParam(emResourceModuleImpl* p1, emCreate const* p2) {
        p1->unk2C = p2->m_epsp ? p2->m_epsp : p1->unk34;
    }

    template<typename T>
    static void DeleteExParam() { }
};
