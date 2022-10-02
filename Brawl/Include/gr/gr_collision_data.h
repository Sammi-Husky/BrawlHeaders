#pragma once

struct VtxData
{
    char _spacer[8];
};

struct JointData
{
    char _spacer[108];
};

struct LineData
{
    short pointX;
    short pointY;
    char _spacer[12];

};

class grCollData
{
    short vtxLen;
    short lineLen;
    short jointLen;
    short unk1;
    VtxData* vtxDataArray;
    LineData* lineDataArray;
    JointData* jointDataArray;
};

