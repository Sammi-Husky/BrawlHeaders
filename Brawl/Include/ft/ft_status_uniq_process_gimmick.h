#pragma once

#include <StaticAssert.h>
#include <so/event/so_gimmick_event_presenter.h>
#include <so/status/so_status_module_impl.h>
#include <types.h>

class soModuleAccesser;

class ftStatusUniqProcessGimmick : public soStatusUniqProcess, public soGimmickEventObserver {
    soModuleAccesser* m_moduleAccsr;
public:
    ftStatusUniqProcessGimmick(soModuleAccesser* moduleAccesser);
    void presentEvent(soGimmickEventArgs* eventInfo, soModuleAccesser* moduleAccesser);

    virtual ~ftStatusUniqProcessGimmick() { }
    virtual void initStatus(soModuleAccesser* moduleAccesser);
    virtual void exitStatus(soModuleAccesser* moduleAccesser, int);

    virtual void notifyEvent(soGimmickEventArgs* eventInfo, soModuleAccesser* moduleAccesser);
    virtual void notifyEventGimmick(soGimmickEventArgs* eventInfo, int* taskId);
};
static_assert(sizeof(ftStatusUniqProcessGimmick) == 0x14, "Class is the wrong size!");

class ftStatusUniqProcessGimmickEaten : public ftStatusUniqProcessGimmick {
public:
    virtual ~ftStatusUniqProcessGimmickEaten() { }
    virtual void initStatus(soModuleAccesser* moduleAccesser);
    virtual void exitStatus(soModuleAccesser* moduleAccesser, int);
    virtual void execStatus(soModuleAccesser* moduleAccesser);

    virtual void notifyEvent(soGimmickEventArgs* eventInfo, soModuleAccesser* moduleAccesser);
};
// TODO confirm size
// static_assert(sizeof(ftStatusUniqProcessGimmickEaten) == 0x14, "Class is the wrong size!");

class ftStatusUniqProcessGimmickTruck : public ftStatusUniqProcessGimmick {
public:
    virtual ~ftStatusUniqProcessGimmickTruck() { }
    virtual void initStatus(soModuleAccesser* moduleAccesser);
    virtual void exitStatus(soModuleAccesser* moduleAccesser, int);
    virtual void execStatus(soModuleAccesser* moduleAccesser);

    virtual void notifyEvent(soGimmickEventArgs* eventInfo, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(ftStatusUniqProcessGimmickTruck) == 0x14, "Class is the wrong size!");

class ftStatusUniqProcessGimmickSpring : public ftStatusUniqProcessGimmick {
public:
    virtual ~ftStatusUniqProcessGimmickSpring() { }
    virtual void initStatus(soModuleAccesser* moduleAccesser);
    virtual void exitStatus(soModuleAccesser* moduleAccesser, int);
    virtual void execStatus(soModuleAccesser* moduleAccesser);

    virtual void notifyEvent(soGimmickEventArgs* eventInfo, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(ftStatusUniqProcessGimmickSpring) == 0x14, "Class is the wrong size!");

class ftStatusUniqProcessGimmickLadder : public ftStatusUniqProcessGimmick {
public:
    virtual ~ftStatusUniqProcessGimmickLadder() { }
    virtual void initStatus(soModuleAccesser* moduleAccesser);
    virtual void exitStatus(soModuleAccesser* moduleAccesser, int);
    virtual void execStatus(soModuleAccesser* moduleAccesser);
    virtual void execFixPos(soModuleAccesser* moduleAccesser);

    // TODO add non-virtual member functions
};
static_assert(sizeof(ftStatusUniqProcessGimmickLadder) == 0x14, "Class is the wrong size!");

class ftStatusUniqProcessGimmickCatapult : public ftStatusUniqProcessGimmick {
public:
    virtual ~ftStatusUniqProcessGimmickCatapult() { }
    virtual void initStatus(soModuleAccesser* moduleAccesser);
    virtual void exitStatus(soModuleAccesser* moduleAccesser, int);
    virtual void execStatus(soModuleAccesser* moduleAccesser);

    virtual void notifyEvent(soGimmickEventArgs* eventInfo, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(ftStatusUniqProcessGimmickCatapult) == 0x14, "Class is the wrong size!");

class ftStatusUniqProcessGimmickDoor : public ftStatusUniqProcessGimmick {
public:
    virtual ~ftStatusUniqProcessGimmickDoor() { }
    virtual void initStatus(soModuleAccesser* moduleAccesser);
    virtual void execStatus(soModuleAccesser* moduleAccesser);

    virtual void notifyEvent(soGimmickEventArgs* eventInfo, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(ftStatusUniqProcessGimmickDoor) == 0x14, "Class is the wrong size!");

class ftStatusUniqProcessGimmickBarrel : public ftStatusUniqProcessGimmick {
    u8 unk14[0x4];
public:
    virtual ~ftStatusUniqProcessGimmickBarrel() { }
    virtual void initStatus(soModuleAccesser* moduleAccesser);
    virtual void exitStatus(soModuleAccesser* moduleAccesser, int);
    virtual void execStatus(soModuleAccesser* moduleAccesser);
    virtual void execStop(soModuleAccesser* moduleAccesser);
    virtual void execFixPos(soModuleAccesser* moduleAccesser);

    virtual void notifyEvent(soGimmickEventArgs* eventInfo, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(ftStatusUniqProcessGimmickBarrel) == 0x18, "Class is the wrong size!");

class ftStatusGimmickUniqProcessPool : public soNullable {
public:
    virtual ~ftStatusGimmickUniqProcessPool() { }
    virtual soStatusUniqProcess* getUniqProcessBarrel() = 0;
    virtual soStatusUniqProcess* getUniqProcessDoor() = 0;
    virtual soStatusUniqProcess* getUniqProcessCatapult() = 0;
    virtual soStatusUniqProcess* getUniqProcessLadder() = 0;
    virtual soStatusUniqProcess* getUniqProcessSpring() = 0;
    virtual soStatusUniqProcess* getUniqProcessTruck() = 0;
    virtual soStatusUniqProcess* getUniqProcessEaten() = 0;
};
static_assert(sizeof(ftStatusGimmickUniqProcessPool) == 0x8, "Class is the wrong size!");

class ftStatusGimmickUniqProcessPoolImpl : public ftStatusGimmickUniqProcessPool {
    ftStatusUniqProcessGimmickBarrel m_barrelProc;
    ftStatusUniqProcessGimmickDoor m_doorProc;
    ftStatusUniqProcessGimmickCatapult m_catapultProc;
    ftStatusUniqProcessGimmickLadder m_ladderProc;
    ftStatusUniqProcessGimmickSpring m_springProc;
    ftStatusUniqProcessGimmickTruck m_truckProc;
    ftStatusUniqProcessGimmickEaten m_eatenProc;
public:
    virtual ~ftStatusGimmickUniqProcessPoolImpl() { }

    virtual soStatusUniqProcess* getUniqProcessBarrel() {
        return &m_barrelProc;
    }

    virtual soStatusUniqProcess* getUniqProcessDoor() {
        return &m_doorProc;
    }

    virtual soStatusUniqProcess* getUniqProcessCatapult() {
        return &m_catapultProc;
    }

    virtual soStatusUniqProcess* getUniqProcessLadder() {
        return &m_ladderProc;
    }

    virtual soStatusUniqProcess* getUniqProcessSpring() {
        return &m_springProc;
    }

    virtual soStatusUniqProcess* getUniqProcessTruck() {
        return &m_truckProc;
    }

    virtual soStatusUniqProcess* getUniqProcessEaten() {
        return &m_eatenProc;
    }
};
// TODO: confirm size
// static_assert(sizeof(ftStatusGimmickUniqProcessPoolImpl) == 0x98, "Class is the wrong size!");

class ftStatusGimmickUniqProcessPoolNull : public ftStatusGimmickUniqProcessPool {
public:
    virtual ~ftStatusGimmickUniqProcessPoolNull() { }

    virtual soStatusUniqProcess* getUniqProcessBarrel() {
        return &g_soStatusUniqProcessNull;
    }

    virtual soStatusUniqProcess* getUniqProcessDoor() {
        return &g_soStatusUniqProcessNull;
    }

    virtual soStatusUniqProcess* getUniqProcessCatapult() {
        return &g_soStatusUniqProcessNull;
    }

    virtual soStatusUniqProcess* getUniqProcessLadder() {
        return &g_soStatusUniqProcessNull;
    }

    virtual soStatusUniqProcess* getUniqProcessSpring() {
        return &g_soStatusUniqProcessNull;
    }

    virtual soStatusUniqProcess* getUniqProcessTruck() {
        return &g_soStatusUniqProcessNull;
    }

    virtual soStatusUniqProcess* getUniqProcessEaten() {
        return &g_soStatusUniqProcessNull;
    }
};
static_assert(sizeof(ftStatusGimmickUniqProcessPoolNull) == 0x8, "Class is the wrong size!");
