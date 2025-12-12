#pragma once

#include <StaticAssert.h>
#include <ut/ut_queue.h>
#include <types.h>

class gfFileIORequest {
public:
    enum Kind {
        Kind0 = 0,
        Del = 2,
        CreateDir = 3,
        CreateVFSystemFile = 5,
        MountVF = 6,
        UnmountVF = 7,
        FormatVF = 8,
        MountSD = 9,
        UnmountSD = 10,
        CheckFreeSize = 12,
        CheckFile = 13,
        CheckDir = 14,
        FindFirst = 15,
        FindFileCount = 16,
        WriteNAND = 20,
    };

    // 0x0
    char* m_pFilepath;
    // 0x4
    int m_offset;
    // 0x8
    int m_readLen;
    // 0xC
    void* m_dest;
    // 0x10
    void* m_heap;
    // 0x14
    s32 m_returnStatus : 8;
    // 0x15 -- seems to be either a format specifier or id used by the VF operations.
    u8 m_vfUnk : 8;

    u8 unk16_1 : 1;
    bool m_isCached : 1;
    u8 unk16_3 : 6;
    // Bits 3+4 are involved in whether or not handle->release() frees this request.

    u8 unk17_pad0 : 2;
    bool unk17_0 : 1;
    bool m_isCancelRequested : 1;
    bool m_isCanceled : 1;
    bool unk17_11 : 1;
    bool unk17_2 : 1;
    bool unk17_3 : 1;

    // 0x18
    bool unk18_0 : 1;
    u8 unk18_pad : 1;
    bool unk18_1 : 1;
    u8 unk18_pad2 : 1;
    Kind m_kind : 8;
    s32 m_isReady : 8;

    // 0x1C
    u16 m_crc16;
    // 0x1E
    u16 m_unk3;
    // 0x20
    void* m_notifyCallback;
    char m_filepath[128];

    void setParam(const char* filepath);
    void setReadParam(const char* filepath, const void* addr, int length, int offset);
    void setReadParam(const char* filepath, void* addr, int length, int offset);
    void setWriteParam(const char* filepath, void* addr, int len, int offset);
};

class gfFileIORequestQueue {
    char _[0x18];
    utQueueInterface<gfFileIORequest*>* m_queue;
public:
    inline u32 getSize() { return m_queue->size(); };
};
static_assert(sizeof(gfFileIORequestQueue) == 0x1c, "Wrong size for class!");
