#pragma once

#include <gf/gf_task.h>
#include <gf/gf_keep_fb.h>

class gfGameApplication
{
public:
    char unk[0xD0];
    gfKeepFrameBuffer keepFB;
    gfGameApplication();
};