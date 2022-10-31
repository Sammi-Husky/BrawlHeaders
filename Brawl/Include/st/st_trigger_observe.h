#pragma once

#include <types.h>
#include <gf/gf_area.h>
#include <gf/gf_callback.h>

struct GimmickAreaData {
    char _spacer[40];
};

class stObsTriggerCB : public gfCallback {

    char _spacer[8];

    virtual ~stObsTriggerCB();
    virtual gfArea* getAreaPointer();
    virtual bool getAreaID(int* areaID);
    virtual void setAreaSleep(bool isSleep);
};

class stObsTriggerArea : public stObsTriggerCB {

    gfArea* area;
    GimmickAreaData gimmickAreaData;

    virtual void userProc();
    virtual ~stObsTriggerArea();
    virtual gfArea* getAreaPointer();
    virtual bool getAreaID(int* areaID);
    virtual void setAreaSleep(bool isSleep);
    virtual GimmickAreaData* getAreaDataPointer();
    virtual void setArea(gfArea* area);
};