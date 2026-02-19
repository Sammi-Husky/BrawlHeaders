#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <so/so_instance_manager.h>

class soEventUnit : public soNullableInterface {
public:
    virtual void eraseObserver(s16 id, s16 sendID);
    virtual s16 getEventId();
    virtual u32 getObserverCapacity(u32 index);
    virtual u32 getObserverSize(u32 index);
    virtual ~soEventUnit() { }
};

class soEventManager {
public:
    virtual s16 addUnit(soEventUnit*);
    virtual void eraseUnit(u32);
    virtual bool isNullUnit(u32);
    virtual void eraseObserver(s16 id, s16 sendID);
    virtual u32 getObserverCapacity(u32 index);
    virtual u32 getObserverSize(u32 index);
    virtual bool isExist(short);
    virtual int getManageId();
    virtual soEventUnit* getEventUnit(short);
};

class soEventSystem {
public:
    soInstanceManagerSimpleEntity<soEventManager*, soArrayVector<soInstanceUnit<soEventManager*>, 500 > > m_instanceManager;

    soEventManager* getManager(short manageID);
    static soEventSystem* getInstance();

};
static_assert(sizeof(soEventSystem) == 4032, "Class is wrong size!");

template <typename T>
class soEventUnitWrapper : public soEventUnit {
public:
    virtual s16 getEventId() { return m_eventID; }
    virtual ~soEventUnitWrapper() {
        if (isValid())
            soEventSystem::getInstance()->getManager(m_managerID)->eraseUnit(m_eventID);
    }
    virtual s16 addObserverSub(T*, s8);

    soEventUnitWrapper(s32 p1, s16 p2) : m_managerID(p1), m_eventID(p2) {
        if (p1 != -1) {
            s16 eid = soEventSystem::getInstance()->getManager(m_managerID)->addUnit(this);
            if (eid > -1)
                m_eventID = eid;
        }
    }

    bool isValid() const { return m_managerID != -1; }

    s16 m_managerID;
    s16 m_eventID;
};

template <typename T>
class soEventUnitImpl : public soEventUnitWrapper<T> {
public:
    soInstanceManagerFullProperty<T*>* m_observerListPtr; // 0x8

    virtual bool isNull() const {
        return false;
    }

    virtual void eraseObserver(s16 id, s16 sendID) {
        m_observerListPtr->erase(id);
    }

    // TODO: shouldn't need index
    virtual u32 getObserverCapacity(u32 index) {
        return m_observerListPtr->capacity();
    }

    // TODO: shouldn't need index
    virtual u32 getObserverSize(u32 index) {
        return m_observerListPtr->size();
    }

    virtual ~soEventUnitImpl() { }

    virtual s16 addObserverSub(T* p1, s8 p2) {
        soInstanceAttributeExt2<T> attr(p1);
        return m_observerListPtr->add(attr.unk0, -1, attr.unk4, p2);
    }
    virtual soInstanceManagerFullProperty<T*>* getObserverListSub() {
        return m_observerListPtr;
    }

    virtual u32 getObserverNum() const = 0;

    soEventUnitImpl(s32 p1, s16 p2) : soEventUnitWrapper<T>(p1, p2) {
        m_observerListPtr = reinterpret_cast<soInstanceManagerFullProperty<T*>*>(
                            reinterpret_cast<u8*>(this) +
                            sizeof(soEventUnitImpl<T>));
    }
};

template <typename T, s32 C>
class soEventUnitWithWorkArea : public soEventUnitImpl<T> {
    soInstanceManagerFullPropertyVector<T*, C> m_observerList; // 0xC
public:
    soEventUnitWithWorkArea(s32 p1, s16 p2) :
        soEventUnitImpl<T>(p1, p2) { }

    virtual ~soEventUnitWithWorkArea() { }
    virtual u32 getObserverNum() const {
        return m_observerList.size();
    }
};
