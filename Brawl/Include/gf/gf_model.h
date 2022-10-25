#pragma once

#include <nw4r/g3d/g3d_anmchr.h>
#include <nw4r/g3d/g3d_anmclr.h>
#include <nw4r/g3d/g3d_anmshp.h>
#include <nw4r/g3d/g3d_anmtexpat.h>
#include <nw4r/g3d/g3d_anmtexsrt.h>
#include <nw4r/g3d/g3d_anmvis.h>
#include <nw4r/g3d/g3d_scnmdl.h>

class gfModelAnimation {
public:
    char _spacer[8];

    AnmObjVisRes* anmObjVisRes;
    AnmObjChrRes* anmObjChrRes;
    AnmObjTexPatRes* anmObjTexPatRes;
    AnmObjTexSrtRes* anmObjTexSrtRes;
    AnmObjMatClrRes* anmObjMatClrRes;
    AnmObjShpRes* anmObjShpRes;

    u16 getFrameCount();
    float getFrame();
    void setFrame(float frame);
    void setUpdateRate(float updateRate);
    void setLoop(bool shouldLoop);
    void unbindNodeAnim(ScnMdl* sceneModel);
};

// Size: 32