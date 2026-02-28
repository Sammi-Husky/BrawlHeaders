#pragma once

#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <so/event/so_event_system.h>
#include <so/so_null.h>
#include <types.h>

class soModuleAccesser;
class StageObject;

template <typename T>
class soEventObserver {
    s16 addObserverPrivate(s32 manageId, T* obsvr, s8 p3) {
        soEventManager* evtMgr = soEventSystem::getInstance()->
                                                getManager(manageId);
        if (!evtMgr->getObserverCapacity(obsvr->m_unitID))
            return -1;
        soEventUnitWrapper<T>* evt = dynamic_cast<soEventUnitWrapper<T>*>(
                                     evtMgr->getEventUnit(obsvr->m_unitID));
        if (!evt)
            return -1;
        s16 res = evt->addObserverSub(obsvr, p3);
        return res;
    }

public:
    virtual void addObserver(s16 param1, s8 param2) { }
    s16 m_manageID;
    s16 m_unitID;
    s16 m_sendID;

    s32 getObserverId() const { return m_sendID; }

    soEventObserver(s16 unitID) {
        m_manageID = -1;
        m_unitID = unitID;
        m_sendID = -1;
    }

    void removeObserver(s16 manageId) {
        const soInstanceManager<soEventManager *> &instMgr =
            soEventSystem::getInstance()->getInstanceManager();
        if (instMgr.isContain(manageId) == true) {
            soEventSystem::getInstance()->getManager(m_manageID)
                ->eraseObserver(m_unitID, m_sendID);
        }
        m_sendID = -1;
        m_manageID = -1;
    }

    ~soEventObserver() {
        removeObserver(m_manageID);
    }

    void addObserverSub(s32 manageId, T* obsvr, s8 p3) {
        bool check4 = false;
        bool check3 = false;
        bool check2 = false;
        bool check1 = false;
        s32 removeID;
        s32 checkID = m_manageID;

        if (m_manageID >= 0 && m_unitID >= 0)
            check1 = true;
        if (check1 && m_sendID > -1)
            check2 = true;
        if (check2 && soEventSystem::getInstance()->getInstanceManager().
                                                    isContain(checkID) == true)
            check3 = true;
        if (check3 && soEventSystem::getInstance()->getManager(m_manageID)->
                                                    getObserverCapacity(m_unitID) == 1)
            check4 = true;
        if (check4 == true) {
            removeID = m_manageID;
            removeObserver(removeID);
        }
        if (manageId <= -1 || m_unitID <= -1 ||
                              soEventSystem::getInstance()->getInstanceManager().
                                                            isContain(manageId) == false)
            return;
        soEventManager* eventManager = soEventSystem::getInstance()->
                                                      getManager(manageId);
        if (eventManager->isNullUnit(m_unitID) != true) {
            m_sendID = addObserverPrivate(manageId, obsvr, p3);
            if (m_sendID > -1 && m_sendID > -1)
                m_manageID = manageId;
        }
    }

    void initialize(s16 param1, s8 param2) {
        addObserver(param1, param2);
    }

    void setupObserver(s16 manageId) {
        bool bVar5 = false;
        bool bVar4 = false;
        bool bVar3 = false;
        bool bVar2 = false;
        if (-1 < m_manageID && -1 < m_unitID) {
            bVar2 = true;
        }
        if (bVar2 && -1 < m_sendID) {
            bVar3 = true;
        }
        if (bVar3) {
            if (soEventSystem::getInstance()->m_instanceManager.isContain(this->m_manageID)) {
                bVar4 = true;
            }
        }
        if (bVar4) {
            if (soEventSystem::getInstance()->getManager(this->m_manageID)->isExist(m_unitID)) {
                bVar5 = true;
            }
        }
        if (bVar5) {
            if (soEventSystem::getInstance()->m_instanceManager.isContain(this->m_manageID)) {
                soEventSystem::getInstance()->getManager(this->m_manageID)->eraseObserver(m_unitID, m_sendID);
            }
            m_sendID = -1;
            m_manageID = -1;
        }
        if (-1 < manageId && -1 < m_unitID) {
            if (soEventSystem::getInstance()->m_instanceManager.isContain(manageId)) {
                soEventManager* eventManager = soEventSystem::getInstance()->getManager(manageId);
                if (!eventManager->isNullUnit(m_unitID)) {
                    int sendId;
                    if (eventManager->isExist(m_unitID)) {
                        soEventUnitWrapper<T>* eventUnit = dynamic_cast<soEventUnitWrapper<T>*>(eventManager->getEventUnit(m_unitID));
                        if (eventUnit == NULL) {
                            sendId = -1;
                        }
                        else {
                            sendId = eventUnit->addObserverSub(static_cast<T*>(this), -1);
                        }
                    }
                    else {
                        sendId = -1;
                    }
                    this->m_sendID = sendId;
                    if (-1 < sendId) {
                        this->m_manageID = manageId;
                    }
                }
            }
        }
    }
};
static_assert(sizeof(soEventObserver<void>) == 0xC, "Class is wrong size!");

template <class T>
class soEventPresenter {
    virtual ~soEventPresenter();

    // TODO: Verify
    char _spacer1[8];
};

class soEventObserverRegistrationDesc : public soNullable {
    virtual ~soEventObserverRegistrationDesc();
    virtual bool checkCollisionHit();
    virtual bool checkCollisionAttack();
    virtual bool checkCollisionCatch();
    virtual bool checkGimmick();
    virtual bool checkStatus();
    virtual bool checkAnimCmd();
    virtual bool checkDamage();
    virtual bool checkLink();
    virtual bool checkSituation();
    virtual bool checkModel();
    virtual bool checkMotion();
    virtual bool checkArticle();
    virtual bool checkItemManage();
    virtual bool checkCapture();
    virtual bool checkCollisionShield();
    virtual bool checkCollisionReflector();
    virtual bool checkCollisionAbsorber();
    virtual bool checkCollisionSearch();
    virtual bool checkTurn();

};
