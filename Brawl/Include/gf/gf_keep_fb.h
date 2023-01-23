#pragma once

#include <gf/gf_task.h>

class gfKeepFrameBuffer
{

private:
public:
    void endKeepScreen();
    void startKeepScreen();
    void render();
    void update();
};