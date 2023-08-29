#pragma once

#include <gf/gf_file_io_request.h>
#include <memory.h>
#include <types.h>

class gfFileIOHandle {
public:
    // 0
    gfFileIORequest* fileToLoad;
    int read(const char* filepath, HeapType heap, int offset);
    int readRequest(const char* filename, HeapType heap, int length, int offset);
    int readRequest(const char* filepath, void* addr, int length, int offset);
    bool isReady();
    int getReturnStatus();
    void* getBuffer();
    size_t getSize();
    void release();
    void cancelRequest();
    gfFileIOHandle()
    {
        fileToLoad = 0;
    }
    ~gfFileIOHandle()
    {
        delete fileToLoad;
    };
};