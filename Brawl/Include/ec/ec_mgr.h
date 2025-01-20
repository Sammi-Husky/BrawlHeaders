#pragma once

#include <gf/gf_task.h>
#include <mt/mt_vector.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <so/ground/so_ground_module_impl.h>
#include <ef/ef_id.h>
#include <types.h>

class ecMgr : public gfTask {

private:
    char unk[0x68];

public:
    ecMgr();
    void setDrawPrio(int prio);
    u32 setEffect(EfID effectID);
    u32 setEffect(EfID effectID, Vec3f* pos);
    u32 setEffect(EfID effectID, Vec3f* pos, Vec3f* rot, Vec3f* scale);
    void endEffect(u32);
    void killEffect(u32, u32, u32);
    void setParent(u32 unk, nw4r::g3d::ScnMdl*, const char*, int);
    void preSetAnmIdx(int chrIndex, int visIndex, int patIndex, int srtIndex, int clrIndex, int shpIndex);
    void setGroundAttach(u32, soGroundModule* groundModule);
    void setGroundAttach(u32, grCollisionLineWork* lineWork);
    void setVisible(u32, bool isVisible);
    void setVisibleGroup(u32, bool isVisible, u32, u32);
    void setPos(u32, Vec3f* pos);
    void setRot(u32, Vec3f* rot);
    void setScl(u32, Vec3f* scale);
    void setMdlTexpat(u32, u32);
    void setMdlAnmIdx(u32, u32, s8);
    void setMdlEnableUpdate(u32, bool, s8);
    void setMdlFrame(u32, float, s8);
    void setSlowRate(u32 effectHandleID, u32 slowMagnitude);
    u32 searchResourceID(char* resourceName);
    virtual ~ecMgr();
};
static_assert(sizeof(ecMgr) == 0xa8, "Class is wrong size!");

extern ecMgr* g_ecMgr;
