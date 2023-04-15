#pragma once
#include <gf/gf_task.h>
#include <nw4r/g3d/g3d_scngroup.h>
class MenuRoot : public gfTask {
public:
    char spacer[0x08];
    ScnGroup* scene;
};
