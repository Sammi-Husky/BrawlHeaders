#pragma once

#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <types.h>

class gfCamera {
public:
    struct OrthoParam {
        float m_top;
        float m_bottom;
        float m_left;
        float m_right;
    };

    enum ProjectionType {
        Projection_Orthogonal = 0x0,
        Projection_Perspective = 0x1,
    };

    char _spacer[96];
    Vec3f m_targetPos;
    Vec3f m_centerPos;
    char _spacer1[100];
    float m_near;
    float m_far;
    char _spacer2[4];
    OrthoParam m_orthoParam;
    char _spacer3[8];
    ProjectionType m_projectionType;
    char _spacer4[48];

    void setGX();
    void calcProjection3Dto2D(Vec3f*, Vec2f*);
};
static_assert(sizeof(gfCamera) == 308, "Class is wrong size!");

class gfCameraManager {
public:
    gfCamera m_cameras[6];
    char _spacer[8];
    static gfCameraManager* getManager();
};
static_assert(sizeof(gfCameraManager) == 0x740, "Class is wrong size!");