#pragma once

#include <types.h>
#include <GX/GXColor.h>

class efScreen {
    char _spacer[492];

public:
    int requestFill(float, int, int, GXColor*);
};

extern efScreen* g_efScreen;