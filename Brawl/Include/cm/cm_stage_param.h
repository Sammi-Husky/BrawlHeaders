#pragma once

#include <types.h>
#include <st/st_positions.h>
#include <mt/mt_vector.h>

struct cmStageParam {
    stRange m_range;
    float m_verticalRotationFactor;
    float m_horizontalRotationFactor;
    float m_minZ;
    float m_maxZ;
    float m_32;
    float m_36;
    float m_40;
    float m_characterBubbleBufferMultiplier;
    float m_48;
    float m_speed;
    float m_tiltThreshold;
    float m_fov;

    STATIC_CHECK(sizeof(cmStageParam) == 0x40)
};

struct cmStageParamFixed {
    Vec3f m_pos;
    float m_fov;
    float m_verticalAngle;
    float m_horizontalAngle;

    STATIC_CHECK(sizeof(cmStageParamFixed) == 24)
};

struct cmStageParamPausedOffsetRange {
    float m_0;
    float m_4;
    float m_8;
    float m_12;

    STATIC_CHECK(sizeof(cmStageParamPausedOffsetRange) == 16)
};

struct cmStageParamPaused {
    float m_angle;
    float m_zoomIn;
    float m_zoomDefault;
    float m_zoomOUt;
    float m_rotYMin;
    float m_rotYMax;
    float m_rotXMin;
    float m_rotXMax;
    Vec3f m_pos;
    cmStageParamPausedOffsetRange m_offsetRange;
    char _60[16];

    STATIC_CHECK(sizeof(cmStageParamPaused) == 76)
};