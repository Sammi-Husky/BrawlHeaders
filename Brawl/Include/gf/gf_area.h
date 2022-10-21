#pragma once

#include <mt/mt_vector.h>

class gfArea {
    char _spacer[0x10];
    int areaID;
    char _spacer2[0x30];

    virtual bool testIntersectShape(void* unk);
    virtual void debugDrawImp();
    virtual void notifyIntersect(int unk);
    virtual void update();
    virtual bool testIncludePos(Vec2f* pos);
};