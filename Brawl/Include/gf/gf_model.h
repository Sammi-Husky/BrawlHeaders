#pragma once

#include <StaticAssert.h>
#include <nw4r/g3d/g3d_anmchr.h>
#include <nw4r/g3d/g3d_anmclr.h>
#include <nw4r/g3d/g3d_anmshp.h>
#include <nw4r/g3d/g3d_anmtexpat.h>
#include <nw4r/g3d/g3d_anmtexsrt.h>
#include <nw4r/g3d/g3d_anmvis.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <types.h>

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

    gfModelAnimation(nw4r::g3d::ResFile* resFile, nw4r::g3d::ResMdl* resMdl, bool doBind, u32 animIndex, HeapType heapType);
    gfModelAnimation(nw4r::g3d::ResFile* resFile, nw4r::g3d::ResMdl* resMdl, bool doBind, const char* animName, HeapType heapType);

    u16 getFrameCount();
    float getFrame();
    void setFrame(float frame);
    float getUpdateRate();
    void setUpdateRate(float updateRate);
    void setLoop(bool shouldLoop);
    void setLoopNode(bool shouldLoop);
    void setLoopVisible(bool shouldLoop);
    void setLoopTex(bool shouldLoop);
    void setLoopTexSrt(bool shouldLoop);
    void setLoopMatCol(bool shouldLoop);
    void unbindNodeAnim(nw4r::g3d::ScnMdl* sceneModel);
    void unbindVisibleAnim(nw4r::g3d::ScnMdl* sceneModel);
    void unbindTexAnim(nw4r::g3d::ScnMdl* sceneModel);
    void unbindTexSrtAnim(nw4r::g3d::ScnMdl* sceneModel);
    void unbindMatColAnim(nw4r::g3d::ScnMdl* sceneModel);
    void unbindShapeAnim(nw4r::g3d::ScnMdl* sceneModel);
    void bindNodeAnim(nw4r::g3d::ScnMdl* sceneModel);
    void bindVisibleAnim(nw4r::g3d::ScnMdl* sceneModel);
    void bindTexAnim(nw4r::g3d::ScnMdl* sceneModel);
    void bindTexSrtAnim(nw4r::g3d::ScnMdl* sceneModel);
    void bindMatColAnim(nw4r::g3d::ScnMdl* sceneModel);
    void bindShapeAnim(nw4r::g3d::ScnMdl* sceneModel);

    static void unbind(nw4r::g3d::ScnMdl* sceneModel);
    static void bind(nw4r::g3d::ScnMdl* sceneModel, gfModelAnimation* modelAnim);
};
static_assert(sizeof(gfModelAnimation) == 32, "Class is wrong size!");

// Size: 32