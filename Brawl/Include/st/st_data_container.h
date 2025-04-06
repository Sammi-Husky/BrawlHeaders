#pragma once

#include <StaticAssert.h>
#include <sr/sr_common.h>
#include <types.h>

struct stDataContainerData {
    u32 m_MAGIC;
    s32 m_numFiles;
    s32 m_version;
    u32 m_extParam;
};

class stDataBaseContainer {
public:
    virtual ~stDataBaseContainer() { }
};
static_assert(sizeof(stDataBaseContainer) == 4, "Class is wrong size!");

class stDataContainer : private stDataBaseContainer {
protected:
    u32 m_headerSize;
    stDataContainerData* m_filedata;
    static const u32 HeaderSize = 8;

public:
    stDataContainer(stDataContainerData* data);
    virtual u32 getVersion() { return 0; }
    virtual u32 getExtParam() { return 0; }
    virtual stDataContainerData* getData(u32 index);
    virtual void* getDataAddressHead();
    virtual ~stDataContainer();
};
static_assert(sizeof(stDataContainer) == 0x0C, "Class is wrong size!");

class stDataSimpleContainer : public stDataContainer {
    static const u32 SimpleHeaderSize = 16;

public:
    stDataSimpleContainer(stDataContainerData* data);
    virtual ~stDataSimpleContainer();
};
static_assert(sizeof(stDataSimpleContainer) == 0x0C, "Class is wrong size!");

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
