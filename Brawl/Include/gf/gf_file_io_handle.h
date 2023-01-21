#pragma once

#include <types.h>
#include <memory.h>
#include <gf/gf_file_io_request.h>

class gfFileIOHandle
{
public:
    // 0
    gfFileIORequest *fileToLoad;
    int readRequest(char *filename, HeapType heap, int length, int offset);
    bool isReady();
    int getReturnStatus();
    void *getBuffer();
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