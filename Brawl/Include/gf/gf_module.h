#pragma once

#include <types.h>
#include <memory.h>
#include <StaticAssert.h>
#include <gf/gf_file_io_handle.h>

class gfModuleInfo {
    void* m_module;
    int m_buffer;
    int m_size;
    char _12[4];
    void* m_heap;
    gfFileIOHandle* m_fileHandle;
    char _24[2];
    char m_moduleName;
    char _30[33];

    STATIC_CHECK(sizeof(gfModuleInfo) == 60)
};

class gfModuleManager {

    HeapType m_heapType;
    void* _4;
    gfModuleInfo m_moduleInfos[16];

    public:
        struct LoadRequestResult {
            void* _0;
        };

        void setTempolaryLoadHeap(HeapType heapType);
        static void loadModuleRequest(LoadRequestResult*, gfModuleManager*, char* moduleName, HeapType heapType, bool, bool);
        static gfModuleManager* getInstance();

    STATIC_CHECK(sizeof(gfModuleManager) == 968)
};


