#pragma once
#include <so/anim/so_anim_cmd.h>
#include <so/event/so_event_presenter.h>
#include <so/event/so_event_observer.h>
#include <so/so_instance_manager.h>

/*
 * This class is weird, it has a bunch of data before the event presenter vtable and info,
 * but the inheritance info doesn't show any other info. I can't get the layout right while
 * inheriting the presenter, so I commented it and added a spacer.
 * 
 * There is an "acCmdInterpreter" class in the code that seems to do a lot
 * of the same things as this class, but it doesn't seem to be the missing
 * inherited object, as it is about 0x10 bigger than this class. It is perhaps
 * the case that the acCmdInterpreter inherits this, but that class doesn't
 * seem to have provided inheritance info.
 *
 * I'm leaving it like this for now, since it is still somewhat useful/usable.
 */
class soAnimCmdInterpreter /*: soEventPresenter<soAnimCmdEventObserver> */ {
public:
    char _inheritance_data[8]; // 0x0; not sure what this is.
    float m_frameSpeed; // 0x8
    soAnimCmd* m_currentCmd; // 0xC
    soAnimCmd* m_startCmd; // 0x10
    char _unk0x14[8]; // 0x14
    soAnimCmd* m_lastWaitCmd; // 0x18
    char _unk0x1C[4]; // 0x1C, event presenter vtable and fields are in here.
    float m_logicalFrame; // 0x20
};
static_assert(sizeof(soAnimCmdInterpreter) == 0x28, "Class is the wrong size!");

// This class is very much unfinished.
class soAnimCmdAddressPackArraySeparate: public soNullableInterface  {
public:
    virtual ~soAnimCmdAddressPackArraySeparate();

    char _unk1[0x4]; // unknown
    soAnimCmd* m_startCmd;
    char _unk2[0x14];
    void* m_returnStack;
};
static_assert(sizeof(soAnimCmdAddressPackArraySeparate) == 0x24, "Class is the wrong size!");

class soAnimCmdControlUnit {
public:
    soAnimCmdInterpreter* m_animCmdInterpreter; // 0x0
    soAnimCmdAddressPackArraySeparate* m_animCmdAddressPackArraySeparate; // 0x4
    int m_id; // 0x8
    short m_type; // 0xC
    short m_unk;  // 0xE
};
static_assert(sizeof(soAnimCmdControlUnit) == 0x10, "Class is the wrong size!");

// Type punning a soInstanceManagerFullPropertyVector<soAnimCmdControlUnit, 11> here.
// The purpose is to name the elements, which are what you want out of this object
// the vast majority of the time.
typedef struct {
    int* m_vtable1;
    char _unk[4];
    int* m_vtable2;
    int* m_vtable3;

    // 0x10
    void* m_soArrayVecVtable1;
    void* m_soArrayVecVtable2;
    u32 m_size; // = 11
    union {
        struct {
            soInstanceUnitFullProperty<soAnimCmdControlUnit> m_actionMain;
            soInstanceUnitFullProperty<soAnimCmdControlUnit> m_subactionMain;
            soInstanceUnitFullProperty<soAnimCmdControlUnit> m_subactionGfx;
            soInstanceUnitFullProperty<soAnimCmdControlUnit> m_subactionSfx;
            soInstanceUnitFullProperty<soAnimCmdControlUnit> m_subactionOther;
            soInstanceUnitFullProperty<soAnimCmdControlUnit> m_altSubactionMain;
            soInstanceUnitFullProperty<soAnimCmdControlUnit> m_altSubactionGfx;
            soInstanceUnitFullProperty<soAnimCmdControlUnit> m_altSubactionSfx;
            soInstanceUnitFullProperty<soAnimCmdControlUnit> m_altSubactionOther;
            soInstanceUnitFullProperty<soAnimCmdControlUnit> m_infiniteLoop;
            soInstanceUnitFullProperty<soAnimCmdControlUnit> m_actionHidden;
        };
        soInstanceUnitFullProperty<soAnimCmdControlUnit> m_asArray[11];
    };
} animCmdControlUnitVectorHelper;

static_assert(sizeof(animCmdControlUnitVectorHelper) 
    == sizeof(soInstanceManagerFullPropertyVector<soAnimCmdControlUnit, 11>), "Class is the wrong size!");

class soAnimCmdModule: public soNullable {
    virtual void registInterpreter();
    virtual void interpretCmd();
    virtual void interpretCmdAdjust();
    virtual void interpretCmd1();
    virtual void resetInterpreter1();
    virtual void resetInterpreter2();
    virtual void resetInterpreter3();
    virtual void resetInterpreter4();
    virtual void isInterpreterAnimCmd();
    virtual void skipNextMotionGroup();
    virtual bool isAnimCmdEnd();
    virtual int getAnimCmdFrame();
    virtual void getCmdAddressPack();
    virtual void setAddressPackList();
    virtual void getInterpreterNum();
    virtual ~soAnimCmdModule();
    virtual void activate();
    virtual void deactivate();
};

class soAnimCmdModuleImpl:
    public soAnimCmdModule,
    public soStatusEventObserver,
    public soAnimCmdEventObserver
{
public:
    // This is a soInstanceManagerFullPropertyVector<soAnimCmdControlUnit, 11>*
    animCmdControlUnitVectorHelper* m_animCmdThreads; // 0x20
};
static_assert(sizeof(soAnimCmdModuleImpl) == 0x24, "Class is the wrong size!");

/* TODO: soAnimCmdModuleNull */