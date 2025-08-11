#pragma once

#include <StaticAssert.h>
#include <gf/gf_archive.h>
#include <gf/gf_file_io.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#include <sr/sr_common.h>
#include <types.h>

class gfResourceLoader : public gfFileIOHandle {
    void* m_compressedRsrcPtr;
    u32 m_allocSize;
    u32 m_rsrcSize;
    void* m_rsrcPtr;
    HeapType m_heapTy;
    gfArchive* m_archive;
    bool m_isLoaded : 1;
    bool m_doCachedRead : 1;

    void* load(HeapType heapTy, const char* path, gfArchive* archive, u32 size);

public:
    void* loadResource(HeapType heapTy, const char* path, gfArchive* archive, u32 freeSpaceToLeave);
    void* loadResourceMemSizeOrder(HeapType heapTy, const char* path, gfArchive* archive, u32 size);
    bool isLoaded();
    void freeResource();
};
static_assert(sizeof(gfResourceLoader) == 0x20, "Class is the wrong size!");
