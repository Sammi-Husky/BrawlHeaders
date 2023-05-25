#pragma once

#include <types.h>
#include <so/so_instance_manager.h>

class soEventUnit : public soNullableInterface {
public:
    virtual void eraseObserver(short, short sendID);
    virtual short getEventId();
    virtual u32 getObserverCapacity(u32 index);
    virtual u32 getObserverSize(u32 index);
    virtual ~soEventUnit();
};

template <class T>
class soEventUnitWrapper : public soEventUnit {
public:
    virtual short getEventId();
    virtual ~soEventUnitWrapper();
    virtual short addObserverSub(T*, int);

    short m_4;
    short m_eventID;
};

class soEventManager {
public:
    virtual void addUnit(soEventUnit*);
    virtual void eraseUnit(u32);
    virtual bool isNullUnit(u32);
    virtual void eraseObserver(short, short sendID);
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
