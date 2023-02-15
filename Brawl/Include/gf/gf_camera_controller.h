#pragma once

#include <types.h>
#include <gf/gf_camera.h>

class gfCameraController {
    gfCameraManager* m_cameraManager;

public:
    virtual void update(float);
    virtual void draw();

    STATIC_CHECK(sizeof(gfCameraController) == 8)
};
