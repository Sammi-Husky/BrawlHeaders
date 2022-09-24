#pragma once

class grNodeCallbackData {
    char _spacer[80];

    char matrix[48];
};

class grCalcWorldCallBack {
protected:
    grNodeCallbackData* nodeCallbackDataArray;
    unsigned int numCallbackData;

    char _spacer[0x04];

public:
    virtual ~grCalcWorldCallBack();
    virtual void ExecCallbackA(int* unk1, int unk2, int* unk3);
    virtual void ExecCallbackB(); // TODO
    virtual void ExecCallbackC(); // TODO
    virtual int initialize(int unk1, int unk2);
    virtual int clearAll();

};




// Size: 16