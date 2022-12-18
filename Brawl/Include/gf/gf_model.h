#pragma once

#include <nw4r/g3d/g3d_anmchr.h>
#include <nw4r/g3d/g3d_anmclr.h>
#include <nw4r/g3d/g3d_anmshp.h>
#include <nw4r/g3d/g3d_anmtexpat.h>
#include <nw4r/g3d/g3d_anmtexsrt.h>
#include <nw4r/g3d/g3d_anmvis.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <types.h>
#include <StaticAssert.h>

class gfModelAnimation {
public:
    nw4r::g3d::ResFile m_resFile;
    char _spacer[4];

    nw4r::g3d::AnmObjVisRes* m_anmObjVisRes;
    nw4r::g3d::AnmObjChrRes* m_anmObjChrRes;
    nw4r::g3d::AnmObjTexPatRes* m_anmObjTexPatRes;
    nw4r::g3d::AnmObjTexSrtRes* m_anmObjTexSrtRes;
    nw4r::g3d::AnmObjMatClrRes* m_anmObjMatClrRes;
    nw4r::g3d::AnmObjShpRes* m_anmObjShpRes;

    u16 getFrameCount();
    float getFrame();
    void setFrame(float frame);
    void setUpdateRate(float updateRate);
    void setLoop(bool shouldLoop);
    void unbindNodeAnim(nw4r::g3d::ScnMdl* sceneModel);
    void unbindShapeAnim(nw4r::g3d::ScnMdl* sceneModel);

    STATIC_CHECK(sizeof(gfModelAnimation) == 32)
};

// Size: 32