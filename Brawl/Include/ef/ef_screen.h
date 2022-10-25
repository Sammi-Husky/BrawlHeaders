#pragma once

#include <containers.h>

class efScreen {
    char _spacer[492];

public:
    int requestFill(float, int, int, Color*);
};

extern efScreen* g_efScreen;