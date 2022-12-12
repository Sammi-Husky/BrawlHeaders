#pragma once

#include <types.h>
#include <StaticAssert.h>

struct OrthographicParameters {
    float m_top;
    float m_bottom;
    float m_left;
    float m_right;
};

enum CameraProjection {
    Camera_Projection_Orthogonal = 0x0,
    Camera_Projection_Perspective = 0x1,
};

class gfCamera {
public:
    char _spacer[108];
    float m_108;
    float m_112;
    char _spacer1[104];
    float m_near;
    float m_far;
    char _spacer2[4];
    OrthographicParameters m_ortho;
    char _spacer3[8];
    CameraProjection m_projection;
    char _spacer4[48];

    STATIC_CHECK(sizeof(gfCamera) == 308)
};

class gfCameraManager {
public:
    gfCamera m_cameras[6];
    char _spacer[8];
    static gfCameraManager* getManager();

    STATIC_CHECK(sizeof(gfCameraManager) == 0x740)
};