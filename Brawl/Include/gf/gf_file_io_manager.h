#pragma once

#include <StaticAssert.h>
#include <gf/gf_thread.h>
#include <gf/gf_file_io_request.h>
#include <types.h>

class gfFileIOManager {
    char _0x0[4];
    gfThread* m_thread;
    gfFileIORequestQueue* m_queue1;
    gfFileIORequestQueue* m_queue2;
    char _0x10[0x8C];
public:
    inline u32 getNumActiveRequests() { return m_queue1->getSize(); };
};
static_assert(sizeof(gfFileIOManager) == 0x9c, "Wrong size for class!");

extern gfFileIOManager* g_gfFileIOManager;
