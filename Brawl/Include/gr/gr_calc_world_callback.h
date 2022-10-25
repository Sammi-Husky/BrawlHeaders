#pragma once

#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>

class grNodeCallbackData {
public:
    char _spacer[8];
    Vec3f pos;
    Vec3f rot;
    Vec3f scale;
    char _spacer2[36];
    Matrix matrix;
};

class grCalcWorldCallBack {

public:
    grNodeCallbackData* nodeCallbackDataArray;
    unsigned int numCallbackData;
    char _spacer[0x04];

    virtual ~grCalcWorldCallBack();
    virtual void ExecCallbackA(int* unk1, int unk2, int* unk3);
    virtual void ExecCallbackB(); // TODO
    virtual void ExecCallbackC(); // TODO
    virtual int initialize(int unk1, int unk2);
    virtual int clearAll();
};

// Size: 16