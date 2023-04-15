#pragma once

#include <StaticAssert.h>
#include <gf/gf_file_io_handle.h>
#include <memory.h>
#include <types.h>

class gfModuleInfo {
public:
    void* m_module;
    int m_buffer;
    int m_size;
    char _12[4];
    void* m_heap;
    gfFileIOHandle* m_fileHandle;
    char _24[2];
    char m_moduleName;
    char _30[33];
};
static_assert(sizeof(gfModuleInfo) == 60, "Class is wrong size!");

class gfModuleManager {

    HeapType m_heapType;
    void* _4;
    gfModuleInfo m_moduleInfos[16];

public:
    struct LoadRequestResult {
        void* _0;
    };

    void setTempolaryLoadHeap(HeapType heapType);
    void destroy(char* moduleName);
    static void loadModuleRequest(LoadRequestResult*, gfModuleManager*, char* moduleName, HeapType heapType, bool, bool);

    static gfModuleManager* getInstance();
};
static_assert(sizeof(gfModuleManager) == 968, "Class is wrong size!");
