#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <gf/gf_task.h>

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

    STATIC_CHECK(sizeof(gfSceneRoot) == 1292)
};

extern gfSceneRoot* g_gfSceneRoot;