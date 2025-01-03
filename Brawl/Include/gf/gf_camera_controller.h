#pragma once

#include <gf/gf_camera.h>
#include <types.h>

class gfCameraController {
    gfCameraManager* m_cameraManager;

public:
    virtual void update(float);
    virtual void draw();
    virtual ~gfCameraController();
};
static_assert(sizeof(gfCameraController) == 8, "Class is wrong size!");
