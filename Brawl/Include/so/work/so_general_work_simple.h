#pragma once

#include <types.h>
#include <so/work/so_general_work_abstract.h>
#include <StaticAssert.h>

class soGeneralWorkSimple : public soGeneralWorkAbstract {
public:
    int* m_intWorks;
    u32 m_intWorkSize;
    float* m_floatWorks;
    u32 m_floatWorkSize;
    u32* m_flagWorks;
    u32 m_flagWorkSize;

    virtual int getIntWork(u32 index);
    virtual void setIntWork(int value, u32 index);
    virtual void addIntWork(int value, u32 index);
    virtual void subIntWork(int value, u32 index);
    virtual void mulIntWork(int value, u32 index);
    virtual void divIntWork(int value, u32 index);
    virtual void incIntWork(u32 index);
    virtual void decIntWork(u32 index);
    virtual u32 getIntWorkSize();
    virtual float getFloatWork(u32 index);
    virtual void setFloatWork(float value, u32 index);
    virtual void addFloatWork(float value, u32 index);
    virtual void subFloatWork(float value, u32 index);
    virtual void mulFloatWork(float value, u32 index);
    virtual void divFloatWork(float value, u32 index);
    virtual u32 getFloatWorkSize();
    virtual void onFlag(u32 flag, u32 index);
    virtual void offFlag(u32 flag, u32 index);
    virtual void clearFlag(u32 index);
    virtual bool isFlag(u32 flag, u32 index);
    virtual u32 turnOffFlag(u32 flag, u32 index);
    virtual u32 getFlagWorkSize();
    virtual void clearWorkAll();
};
static_assert(sizeof(soGeneralWorkSimple) == 36, "Class is wrong size!");