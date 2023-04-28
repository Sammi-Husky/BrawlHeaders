#pragma once

#include <gf/gf_task.h>
#include <mt/mt_vector.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <types.h>

class ecMgr : public gfTask {

private:
    char unk[0xa8];

public:
    ecMgr();
    void setDrawPrio(int prio);
    u32 setEffect(u32 effectID);
    u32 setEffect(u32 effectID, Vec3f* pos);
    u32 setEffect(u32 effectID, Vec3f* pos, Vec3f* rot, Vec3f* scale);
    void endEffect(u32);
    void killEffect(u32, u32, u32);
    void setParent(u32 unk, nw4r::g3d::ScnMdl*, char*, int);
    virtual ~ecMgr();
};

extern ecMgr* g_ecMgr;