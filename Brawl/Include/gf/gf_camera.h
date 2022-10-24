#pragma once

class gfCamera {
public:
    char _spacer[220];
    float near;
    float far;
    char _spacer2[4];
    float top;
    float bottom;
    float left;
    float right;
    char _spacer3[8];
    int cameraPerspective;
    char _spacer4[48];

};

class gfCameraManager {
public:
    gfCamera cameras[6];
    char _spacer[8];
    static gfCameraManager* getManager();
};