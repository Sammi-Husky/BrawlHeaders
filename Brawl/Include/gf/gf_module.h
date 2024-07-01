#pragma once

#include <StaticAssert.h>
#include <gf/gf_file_io_handle.h>
#include <memory.h>
#include <types.h>

// Documentation from Brawllib

class gfModuleHeader {
public:
    u32 id;
    u32 linkNext;
    u32 linkPrev;
    u32 numSections;
    u32 sectionInfoOffset;
    u32 nameOffset;
    u32 nameSize;
    u32 version;

    u32 bssSize;
    u32 relOffset;
    u32 impOffset;
    u32 impSize;

    char prologSection;
    char epilogSection;
    char unresolvedSection;
    char bssSection;

    u32 prologOffset;
    u32 epilogOffset;
    u32 unresolvedOffset;

    u32 moduleAlign;
    u32 bssAlign;

    u32 commandOffset;

    u32 getTextSectionAddr();
};

class gfModule {
public:
    gfModuleHeader* header;
    char unk[0x27];

    static gfModule* create(void* heap, void* buffer, size_t size);
};

class gfModuleInfo {
public:
    gfModule* m_module;
    int m_buffer;
    int m_size;
    char _12[4];
    void* m_heap;
    gfFileIOHandle* m_fileHandle;
    char _24;
    char m_flags;
    char m_moduleName;
    char _30[33];
};
static_assert(sizeof(gfModuleInfo) == 60, "Class is wrong size!");

class gfModuleManager {

public:
    HeapType m_loadHeap;
    void* m_loadHeapAddr;
    gfModuleInfo m_moduleInfos[16];

    struct LoadRequestResult {
        void* _0;
    };

    void setTempolaryLoadHeap(HeapType heapType);
    void destroy(const char* moduleName);
    void loadModuleRequestOnImage(const char* moduleName, HeapType heapType, gfModuleHeader* moduleHeader, int* nodeSize);
    static void loadModuleRequest(LoadRequestResult*, gfModuleManager*, const char* moduleName, HeapType heapType, bool, bool);

    static gfModuleManager* getInstance();
};
static_assert(sizeof(gfModuleManager) == 968, "Class is wrong size!");
