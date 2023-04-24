#pragma once

#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <types.h>

class gfSceneRoot : public gfTask {
    char _spacer[1228];

public:
    virtual void processAnim();
    virtual void processFixCamera();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void renderDebug();
    virtual ~gfSceneRoot();

    void setCurrentFrame(float);
    void removeResAnmScn();
};
static_assert(sizeof(gfSceneRoot) == 1292, "Class is wrong size!");

extern gfSceneRoot* g_gfSceneRoot;