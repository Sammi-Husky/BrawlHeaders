#pragma once

#include <nw4r/g3d/g3d_anmchr.h>
#include <nw4r/g3d/g3d_anmclr.h>
#include <nw4r/g3d/g3d_anmshp.h>
#include <nw4r/g3d/g3d_anmtexpat.h>
#include <nw4r/g3d/g3d_anmtexsrt.h>
#include <nw4r/g3d/g3d_anmvis.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_resfile.h>

class gfModelAnimation {
public:
    nw4r::g3d::ResFile resFile;
    char _spacer[4];

    nw4r::g3d::AnmObjVisRes* anmObjVisRes;
    nw4r::g3d::AnmObjChrRes* anmObjChrRes;
    nw4r::g3d::AnmObjTexPatRes* anmObjTexPatRes;
    nw4r::g3d::AnmObjTexSrtRes* anmObjTexSrtRes;
    nw4r::g3d::AnmObjMatClrRes* anmObjMatClrRes;
    nw4r::g3d::AnmObjShpRes* anmObjShpRes;

    u16 getFrameCount();
    float getFrame();
    void setFrame(float frame);
    void setUpdateRate(float updateRate);
    void setLoop(bool shouldLoop);
    void unbindNodeAnim(nw4r::g3d::ScnMdl* sceneModel);
};

// Size: 32