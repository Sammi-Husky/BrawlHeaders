#pragma once

#include <StaticAssert.h>
#include <so/so_null.h>
#include <types.h>

class soResourceModule : private soNull, public soNullable {
    virtual ~soResourceModule();
    virtual void* getResourceIdAccesser();
    virtual u8 getGroupNo(int unk1);
    virtual void setGroupNo(char unk1, short index);
    virtual int* getTexFile(int unk1, int unk2);
    virtual int* getMdlFile(int unk1, int unk2);
    virtual int* getAnmFile(int unk1, int unk2, int unk3);
    virtual int* getBinFile(int unk1, int unk2, int unk3);
    virtual int* getFile(int unk1, int unk2, int unk3);
};

// TODO: size
class soResourceIdAccesserImpl {

};

class soResourceModuleImpl : public soResourceModule {
    // 0xC
    int m_managerID;
    // 0x10
    void* m_resourceIdAccesser;
    // 0x14
    char m_archiveType1;
    // 0x15
    char m_archiveType2;
    // 0x16
    char m_archiveType3;
    // 0x17
    char m_archiveType4;
public:
    soResourceModuleImpl(u32 p1, soResourceIdAccesserImpl* rsrcIdAcc, u32 p3);

    virtual ~soResourceModuleImpl();
    virtual void* getResourceIdAccesser() { return m_resourceIdAccesser; }
    virtual u8 getGroupNo(int unk1) {
        u8* ptr = (u8*)((int)this + unk1);
        return ptr[0x14];
    }
    virtual void setGroupNo(char unk1, short index);
    virtual int* getTexFile(int unk1, int unk2);
    virtual int* getMdlFile(int unk1, int unk2);
    virtual int* getAnmFile(int unk1, int unk2, int unk3);
    virtual int* getBinFile(int unk1, int unk2, int unk3);
    virtual int* getFile(int unk1, int unk2, int unk3);
};
static_assert(sizeof(soResourceModuleImpl) == 24, "Class is wrong size!");
