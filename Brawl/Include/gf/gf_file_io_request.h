#pragma once

#include <types.h>

class gfFileIORequest {
public:
    char* m_pFilepath;
    int m_offset;
    int m_readLen;
    void* m_dest;
    void* m_heap;
    int m_unk1;
    int m_unk2;
    u16 m_crc16;
    u16 m_unk3;
    int m_unk4;
    char m_filepath[128];

    static void setReadParam(gfFileIORequest* request, const char* filepath, void* addr, int length, int offset);
};
