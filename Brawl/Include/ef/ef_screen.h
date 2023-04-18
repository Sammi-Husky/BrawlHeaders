#pragma once

#include <GX/GXColor.h>
#include <types.h>

class efScreen {
    char _spacer[492];

public:
    int requestFill(float, int, int, GXColor*);
};

extern efScreen* g_efScreen;