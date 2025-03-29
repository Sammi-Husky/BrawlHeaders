#pragma once

#include <gf/gf_camera_controller.h>

class cmAIController : public gfCameraController {
    // TODO fields
public:
    virtual void update(float p1);
    virtual void draw();
    virtual ~cmAIController();
    virtual void updateCameraPosTarget();
    void updateMeleeFix(float p1);
};
// TODO size assertion

extern cmAIController* g_cmAIController;
