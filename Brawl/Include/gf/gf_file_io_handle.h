#pragma once

#include <gf/gf_file_io_request.h>
#include <memory.h>
#include <types.h>

class gfFileIOHandle {
public:
    // 0
    gfFileIORequest* fileToLoad;
    int readRequest(char* filename, HeapType heap, int length, int offset);
    int readRequest(char* filepath, void* addr, int length, int offset);
    bool isReady();
    int getReturnStatus();
    void* getBuffer();
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