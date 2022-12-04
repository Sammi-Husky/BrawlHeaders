#pragma once

#include <types.h>
#include <so/so_null.h>
#include <StaticAssert.h>

class soResourceModule : public soNull, public soNullable {
    virtual ~soResourceModule();
    virtual void* getResourceIdAccesser();
    virtual char getGroupNo(int unk1);
    virtual void setGroupNo(char unk1, short index);
    virtual int* getTexFile(int unk1, int unk2);
    virtual int* getMdlFile(int unk1, int unk2);
    virtual int* getAnmFile(int unk1, int unk2, int unk3);
    virtual int* getBinFile(int unk1, int unk2, int unk3);
    virtual int* getFile(int unk1, int unk2, int unk3);
};

class soResourceModuleImpl : public soResourceModule {
    // 0xC
    int managerID;
    // 0x10
    void* resourceIdAccesser;
    // 0x14
    char archiveType1;
    // 0x15
    char archiveType2;
    // 0x16
    char archiveType3;
    // 0x17
    char archiveType4;

    virtual ~soResourceModuleImpl();
    virtual void* getResourceIdAccesser();
    virtual char getGroupNo(int unk1);
    virtual void setGroupNo(char unk1, short index);
    virtual int* getTexFile(int unk1, int unk2);
    virtual int* getMdlFile(int unk1, int unk2);
    virtual int* getAnmFile(int unk1, int unk2, int unk3);
    virtual int* getBinFile(int unk1, int unk2, int unk3);
    virtual int* getFile(int unk1, int unk2, int unk3);

    STATIC_CHECK(sizeof(soResourceModuleImpl) == 24)

};
