#pragma once

#include <StaticAssert.h>
#include <so/so_array.h>
#include <so/so_null.h>
#include <types.h>

// TODO: confirm class name
struct acCmdArgConv {
    s32 argType;
    // IntData, StringData, ValueIndexData, FloatData, AddressData, BoolData
    s32 data;
};

class acCmdArg {
    const acCmdArgConv *m_dataPtr;
    u8 m_isNull;
public:
    acCmdArg() : m_dataPtr(0), m_isNull(false) { }

    bool isNull() const { return m_isNull; }

    // 0: getIntData
    // 1: getFloatData
    // 2: getAddressData
    // 3: getBoolData?
    // 4: getStringData?
    // 5: getValueIndexData?
    s32 getArgType() const {
        if (m_isNull == 1) {
            return -1;
        }
        return m_dataPtr->argType;
    }

    s32 getIntData() const {
        if (m_isNull == 1) {
            return 0;
        }
        return m_dataPtr->data;
    }

    float getFloatData() const {
        if (m_isNull == 1) {
            return 0.0f;
        }
        return m_dataPtr->data / 60000.0f;
    }

    void* getAddressData() {
        if (m_isNull == 1) {
            return 0;
        }
        return (void*) m_dataPtr->data;
    }
};

// TODO: confirm class name
struct acAnimCmdConv
{
    s8 group; // group 0 refers to systemCmds, >= 1 notSystemCmds
    s8 type;  // when group == 0, selects one of the 25 systemCmds to interpret
    s8 argNum;
    u8 option;
    const acCmdArgConv *args;
};

class acAnimCmd : public soNullable {
public:
    virtual s8 getGroup() const = 0;
    virtual s8 getType() const;
    virtual s32 getArgNum() const;
    virtual u8 getOption() const;
    virtual soArrayContractibleTable<const acCmdArgConv> getArgList();
    virtual bool getArg(acCmdArg *arg, s32 index) const;
    virtual const acAnimCmdConv *getCmdAddress() const;
    virtual bool isArgEmpty() const;
    virtual bool isValid() const;
};

class acAnimCmdImpl : public acAnimCmd {
public:
    const acAnimCmdConv* cmdAddr;

    acAnimCmdImpl() : cmdAddr(0) { }
    virtual s8 getGroup() const;
    virtual s8 getType() const;
    virtual s32 getArgNum() const;
    virtual u8 getOption() const;
    virtual soArrayContractibleTable<const acCmdArgConv> getArgList();
    virtual bool getArg(acCmdArg *arg, s32 index) const;
    virtual const acAnimCmdConv *getCmdAddress() const { return cmdAddr; }
    virtual bool isArgEmpty() const;
    virtual bool isValid() const;
    virtual ~acAnimCmdImpl() { }
};
static_assert(sizeof(acAnimCmdImpl) == 0xC, "Class is the wrong size!");

class acAnimCmdNull : public acAnimCmd {
    virtual s8 getGroup() const;
    virtual s8 getType() const;
    virtual s32 getArgNum() const;
    virtual u8 getOption() const;
    virtual soArrayContractibleTable<const acCmdArgConv> getArgList();
    virtual bool getArg(acCmdArg *arg, s32 index) const;
    virtual const acAnimCmdConv *getCmdAddress() const;
    virtual bool isArgEmpty() const;
    virtual bool isValid() const;
    virtual ~acAnimCmdNull();
};

extern "C" acAnimCmdNull g_acAnimCmdNull;
