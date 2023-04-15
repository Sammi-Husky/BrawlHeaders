#pragma once

#include <StaticAssert.h>
#include <memory.h>
#include <types.h>

struct stDataContainerData {
    u32 m_MAGIC;
    s32 m_numFiles;
    s32 m_version;
    u32 m_extParam;
};

class stDataContainer {
private:
    u32 m_headerSize;
    stDataContainerData* m_filedata;

public:
    virtual u32 getVersion();
    virtual u32 getExtParam();
    virtual stDataContainerData* getData(int index);
    virtual void* getDataAddressHead();
    virtual ~stDataContainer();
};
static_assert(sizeof(stDataContainer) == 0x0C, "Class is wrong size!");

class stDataMultiContainer : public stDataContainer {
private:
    short m_maxFiles;
    short m_numFiles;
    stDataContainer** m_nodes;

public:
    static stDataMultiContainer* create(void* filedata, HeapType destHeap);
    u32 getVersion();
    u32 getExtParam();
    void* getContainerData(u32 targetMagic, int nodeDataIdx, int nodeIdx);
    int getContainerDataNum(u32 targetMagic, int nodeIdx);
    stDataContainer* searchContainer(u32 targetMagic, int nodeIdx);
};
static_assert(sizeof(stDataMultiContainer) == 0x14, "Class is wrong size!");
