#pragma once

#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#include <StaticAssert.h>
#include <types.h>

class grNodeCallbackData {
public:
    char _spacer[4];
    int _pad : 25;
    bool m_flag7 : 1; // & 0x40
    bool m_flag6 : 1; // & 0x20
    bool m_flag5 : 1; // & 0x10
    bool m_flag4 : 1; // & 8
    bool m_flag3 : 1; // & 4
    bool m_flag2 : 1; // & 2
    bool m_flag1 : 1; // & 1
    Vec3f pos;
    Vec3f rot;
    Vec3f scale;
    char _spacer2[36];
    Matrix matrix;

    STATIC_CHECK(sizeof(grNodeCallbackData) == 128)
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