#pragma once

#include <types.h>
#include <gf/gf_camera_controller.h>
#include <nw4r/g3d/g3d_anmscn.h>

class cmAnimationController : public gfCameraController {
    char _8[28];

public:
    virtual void update(float);

    bool setScnAnmRes(nw4r::g3d::SCN0**, u32);
    void releaseScnAnmRes();

    STATIC_CHECK(sizeof(cmAnimationController) == 0x24)
};

