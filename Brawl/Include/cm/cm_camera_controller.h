#pragma once

#include <types.h>
#include <gf/gf_task.h>
#include <st/st_positions.h>
#include <cm/cm_controller_anm.h>
#include <cm/cm_quake.h>

class CameraParam {
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

    STATIC_CHECK(sizeof(CameraParam) == 0x40)
};

class CameraParamFixed {
    Vec3f m_pos;
    float m_fov;
    float m_verticalAngle;
    float m_horizontalAngle;

    STATIC_CHECK(sizeof(CameraParamFixed) == 24)
};

class CameraParamPaused {
    float m_angle;
    float m_zoomIn;
    float m_zoomDefault;
    float m_zoomOUt;
    float m_rotYMin;
    float m_rotYMax;
    float m_rotXMin;
    float m_rotXMax;
    Vec3f m_pos;
    float m_44;
    float m_48;
    float m_52;
    float m_56;
    char _60[16];

    STATIC_CHECK(sizeof(CameraParamPaused) == 76)
};


class CameraController : public gfTask {
public:
    enum Kind {
        None = 0x0,
        Animation = 0x1,
        AI = 0x2,
        Adventure = 0x3,
        AdventureFree = 0x4,
        AnimationLocked = 0x5,
        FighterTarget = 0x6,
        Photo = 0x7,
        MenuPad = 0x8,
        MenuFixed = 0x9,
        FigDisp1 = 0xa,
        Tech = 0xb,
        MeleeFixed = 0xc,
        Demo = 0xd,
        Default = 0xe
    };

    Kind m_currentControllerKind;
    char _68[4];
    gfCameraController* m_currentController;
    gfCameraController* m_defaultController;
    cmAnimationController* m_animationController;
    gfCameraController* m_fighterTargetController;
    gfCameraController* m_aiController;
    gfCameraController* m_meleeFixedController;
    gfCameraController* m_adventureController;
    gfCameraController* m_adventureFreeController;
    gfCameraController* m_photoController;
    gfCameraController* m_menuPadController;
    gfCameraController* m_menuFixedController;
    gfCameraController* m_figDisp1Controller;
    gfCameraController* m_techController;
    void* m_quake;
    gfCameraController* m_demoController;
    CameraParam m_cameraParam;
    CameraParamPaused m_cameraParamPaused;
    CameraParamFixed m_cameraParamFixed;
    stRange m_cameraRange;
    stRange m_deadRange;
    char _328[92];

    virtual void processCamera();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual ~CameraController();

    void changeInput(Kind cameraControllerKind);
    static CameraController* getInstance();

    STATIC_CHECK(sizeof(CameraController) == 420)
};